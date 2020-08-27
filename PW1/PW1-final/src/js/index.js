(function ($) {
    $(function () {
        let base_url = "https://tiagoifsp.ddns.net/noticias";
        Project.initMenu(base_url);
        Project._initCreateNews();
    });

    const selectors = {
        $menu: $("#menu-wrapper"),
        $content: $("#content"),
        $document: $(document),
    }

    let categories = [];

    const Project = {

        /*
        * Initialize menu
        * */
        initMenu(base_url) {
            $.ajax({
                url: base_url + "/categorias/listar.php",
                type: 'GET',
                success: function (data) {
                    categories = data
                    Project.renderMenu(data);

                    $("#menu-wrapper").find("p").toArray().forEach(el => {
                        $(el).on('click', (e) => {
                            $("#menu-wrapper").find("p.active").removeClass('active')
                            $(e.target).addClass("active");
                        })
                    })

                }
            })
        },

        /*
        * Get categories and creates li for each one
        * */
        renderMenu(data) {
            // check if there is 1 valid category
            if (data.size < 1) {
                selectors.$content.append(`<p class="text-center font-weight-bold">Infelizmente, nenhuma notícia foi encontrada!</p>`)
                console.log("nenhuma categoria encontrada");
                return;
            }

            data.forEach(el => {
                selectors.$menu.append(`<li class="nav-item item" id="${el.id}" data-item><p class="nav-link">${el.nome}</p></li>`)
            })


            selectors.$menu.find("li").filter(".item").on('click', (e) => {
                this._initShowNews(e.currentTarget.id)
            })
        },

        /*
        * Listener for create news
        * */
        _initCreateNews() {
            selectors.$document.on('click', "li#createNews", (e) => {
                selectors.$content.empty();
                selectors.$content.append(`
                    <h2 class="text-center">Cadastrar Notícia</h2>
                    <form action="https://tiagoifsp.ddns.net/noticias/noticias/cadastrar.php" method="POST" id="createNews">
                        <div class="form-group">
                            <label for="category">Categoria</label>
                            <select class="form-control" id="category" name="idCategoria" required></select>
                            <span style="color: red; display: none" error-message>Esse campo é obrigatório</span>
                        </div>
            
                        <div class="form-group">
                            <label for="titulo">Título da notícia</label>
                            <input placeholder="Título" type="text" class="form-control" id="titulo" name="titulo" required />
                            <span style="color: red; display: none" error-message>Esse campo é obrigatório</span>
                        </div>
                        
                        <div class="form-group">
                            <label for="subtitle">Subtitulo da notícia</label>
                            <input placeholder="Subtitulo" type="text" class="form-control" id="subtitle" name="subtitulo" required />
                            <span style="color: red; display: none" error-message>Esse campo é obrigatório</span>
                        </div>
            
                        <div class="form-group">
                            <label for="textContent">Conteúdo</label>
                            <textarea class="form-control" id="textContent" rows="3" name="conteudo" required></textarea>
                            <span style="color: red; display: none" error-message>Esse campo é obrigatório</span>
                        </div>
                        
                        <button type="button" class="btn btn-primary" id="lala">
                            Cadastrar
                        </button>
                    </form>
                `)

                categories.forEach(category => {
                    $("#category").append(`
                        <option id="${category.id}" value="${category.id}">${category.nome}</option>
                    `)
                })

                $("button[type='button']").on("click", (e) => {
                    $("form#createNews").find("[error-message]").toArray().forEach(el => $(el).css("display", "none"));
                    let send = true;

                    // check fields
                    selectors.$content.find("form#createNews").find("[required]").toArray().forEach(field => {
                        if ($(field).val() == "") {
                            $(field).parent().find("[error-message]").css("display", "inline-block");
                            send = false;
                        }
                    })

                    if (send) {
                        $.ajax({
                            url: 'https://tiagoifsp.ddns.net/noticias/noticias/cadastrar.php',
                            type: 'POST',
                            dataType: 'JSON',
                            data: $("form#createNews").serialize(),
                            success: () => {
                                $("form")[0].reset();
                            },
                            error: (err) => {
                                console.log(err.responseJSON)
                            }
                        })
                    }

                })
            })
        },

        _initShowNews(category) {
            selectors.$content.empty();

            $.ajax({
                url: 'https://tiagoifsp.ddns.net/noticias/noticias/listar.php',
                type: 'GET',
                dataType: 'JSON',
                data: {
                    "id": category
                },
                success: data => this._renderNews(data)
            })
        },

        _renderNews(data) {
            if (data.length <= 0) {
                selectors.$content.append(`<p class="text-center font-weight-bold">Não teve notícias</p>`)
            }

            data.forEach(d => {
                selectors.$content.append(`
                    <div id="${d.id}" class="mb-4">
                        <h2 class="text-left">${d.titulo}</h2>
                        <h3 class="text-left">${d.subtitulo}</h3>
                        <p>${d.conteudo}</p>
                        <div class="flex-column" button-container>                           
                            <button type="button" class="btn btn-danger del">
                                Deletar
                            </button>
                        </div>
                    </div>                  
                `)

                if (d.editavel == 1) {
                    $("div[button-container]").last().append(`
                        <button type="button" class="btn btn-primary edit">
                            Editar
                        </button>
                    `)
                }
            })

            // delete news
            selectors.$content.find("button.del").on('click', (e) => {
                let parent = $(e.currentTarget).parent().parent();

                let idDeleteNews = $(parent).prop("id")

                $.ajax({
                    url: 'https://tiagoifsp.ddns.net/noticias/noticias/deletar.php',
                    type: 'GET',
                    dataType: 'JSON',
                    data: {
                        "id": idDeleteNews
                    },
                    success: function () {
                        $(parent).remove()
                    }
                })

            })

            // edit news
            selectors.$content.find("button.edit").on('click', (e) => {
                let parent = $(e.currentTarget).parent().parent();

                let data = {
                    id: parent.attr('id'),
                    title: parent.find("h2").text(),
                    subtitle: parent.find("h3").text(),
                    content: parent.find("p").text()
                }

                this._editNews(data)

            })
        },

        _editNews(data) {
            selectors.$content.empty();

            selectors.$content.append(`
                <h2 class="text-center">Editar Notícia</h2>
                <form action="https://tiagoifsp.ddns.net/noticias/noticias/editar.php" method="POST" id="updateNews">
                    <input type="hidden" name="id" value="${data.id}">
                    <div class="form-group">
                        <label for="category">Categoria</label>
                        <select class="form-control" id="category" name="idCategoria" required></select>
                        <span style="color: red; display: none" error-message>Esse campo é obrigatório</span>
                    </div>
        
                    <div class="form-group">
                        <label for="titulo">Título da notícia</label>
                        <input placeholder="Título" type="text" class="form-control" id="titulo" name="titulo" value="${data.title}" required/>
                        <span style="color: red; display: none" error-message>Esse campo é obrigatório</span>
                    </div>
                    
                    <div class="form-group">
                        <label for="subtitle">Subtitulo da notícia</label>
                        <input placeholder="Subtitulo" type="text" class="form-control" id="subtitle" name="subtitulo" value="${data.subtitle}" required/>
                        <span style="color: red; display: none" error-message>Esse campo é obrigatório</span>                        
                    </div>
        
                    <div class="form-group">
                        <label for="textContent">Conteúdo</label>
                        <textarea class="form-control" id="textContent" rows="3" name="conteudo" required>${data.content}</textarea>
                        <span style="color: red; display: none" error-message>Esse campo é obrigatório</span>
                    </div>
                    
                    <button type="button" class="btn btn-primary">
                        Salvar
                    </button>
                </form>
            `)

            categories.forEach(category => {
                $("#category").append(`
                            <option id="${category.id}" value="${category.id}">${category.nome}</option>
                        `)
            })

            $("button[type='button']").on("click", (e) => {

                $("form#updateNews").find("[error-message]").toArray().forEach(el => $(el).css("display", "none"));
                let send = true;

                // check fields
                selectors.$content.find("form#updateNews").find("[required]").toArray().forEach(field => {
                    if ($(field).val() == "") {
                        $(field).parent().find("[error-message]").css("display", "inline-block");
                        send = false;
                    }
                })

                if (send) {
                    $.ajax({
                        url: 'https://tiagoifsp.ddns.net/noticias/noticias/editar.php',
                        type: 'POST',
                        dataType: 'JSON',
                        data: $("form#updateNews").serialize(),
                        success: () => {
                            let form = $($("form")[0]);
                            let category = form.find("#category").val();

                            form.find("#titulo").val("");
                            form.find("#subtitle").val("");
                            form.find("#textContent").val("");

                            $(e.currentTarget).parent().append(`
                                <span style="display: block; margin-top: 10px; color: green;">Atualizado com sucesso! Você será redirecionado para as notícias em 3s.</span>
`                           )

                            setTimeout(function(){
                                selectors.$content.empty();
                                Project._initShowNews(category)
                            }, 3000);
                        },
                        error: (err) => {
                            console.log(err.responseJSON)
                        }
                    })
                }
            })


        }

    }
})(jQuery);

