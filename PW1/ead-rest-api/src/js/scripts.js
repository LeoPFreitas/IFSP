(function () {

    toastr.options = {
        "closeButton": false,
        "debug": false,
        "newestOnTop": true,
        "progressBar": false,
        "positionClass": "toast-top-right",
        "preventDuplicates": true,
        "onclick": null,
        "showDuration": "300",
        "hideDuration": "1000",
        "timeOut": "5000",
        "extendedTimeOut": "1000",
        "showEasing": "swing",
        "hideEasing": "linear",
        "showMethod": "fadeIn",
        "hideMethod": "fadeOut"
    }

    let selectors = {
        searchButton: $("button#searchButton"),
        searchInput: $("input#searchInput"),
        searchedProgramTable: $("table#searchedProgramTable"),
        showInfoTable: $("table#showInfos"),
        modalTitle: $("h5#modalTitle"),

    }

    let variables = {
        base_url: `http://api.tvmaze.com/`
    }

    selectors.searchButton.on("click", (e) => {
        selectors.searchedProgramTable.find("tbody").empty();
        let query = selectors.searchInput.val();

        $.ajax({
            url: variables.base_url + "search/shows?q=" + query,
            method: "get",
            success: function (data) {
                console.log(data.length)
                if (data.length === 0) {
                    toastr.info('Nenhum programa encontrado', 'Olá')
                }

                data.forEach(found => {
                    selectors.searchedProgramTable.find("tbody").append(
                        `<tr>
                            <td>${found.show.id}</td>
                            <td>${found.show.name}</td>
                            <td>${found.score}</td>
                            <td>
                                <button type="button" class="btn btn-primary" data-toggle="modal" 
                                        data-target="#exampleModalLong" data-id="${found.show.id}"
                                        data-name="${found.show.name}">
                                    Ver mais
                                </button>
                            </td>
                        </tr>`
                    )
                })
            },
            error: function (err) {
                console.log(err);
            }
        });

    })

    /*
    * Modal handler
    * */
    $('#exampleModalLong').on('show.bs.modal', function (event) {
        let button = $(event.relatedTarget)
        let tvDataID = button.data('id')
        let tvDataName = button.data('name')

        // retrieve data
        $.ajax({
            url: variables.base_url + `shows/${tvDataID}/episodes`,
            method: "get",
            success: function (data) {
                if (data.length === 0) {
                    toastr.info('Nenhum episódio encontrado', 'Olá')
                }

                selectors.modalTitle.text(`${tvDataName} episodes list`);

                data.forEach(found => {
                    selectors.showInfoTable.find("tbody").append(`
                        <tr>
                            <td colspan="3">${found.name}</td>
                            <td>${found.number}</td>
                            <td>${found.season}</td>
                            <td>${found.airdate}</td>
                        </tr>
                    `)
                })
            },
            error: function (err) {
                console.log(err);
            }
        });
    })
})()