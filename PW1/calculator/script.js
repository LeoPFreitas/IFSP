function initCalc() {}

const Calc = {
  init() {
    expression = "";
    // initialize the calc object
    calc = document.getElementById("calc-section").children;

    this.calc();
  },

  calc() {
    try {
      for (let i = 0; i < calc.length; i++) {
        // get especial events
        const element = calc[i];

        if (element.textContent === "AC") {
          element.addEventListener("click", () => {
            this.clearMemory();
          });
        } else if (element.textContent === "=") {
          element.addEventListener("click", () => {
            const res = this.evalCalc(expression);
            if (res == undefined || res == null || res == Infinity) {
              return alert("Expressão inválida.");
            } else {
              return alert("O resultado é: ".concat(res));
            }
          });
        } else {
          element.addEventListener("click", () => {
            expression = expression.concat(element.textContent);
          });
        }
      }
    } catch (err) {
      console.log(err);
      alert(
        "Houve um erro na inicializacao de sua aplicacao. Por favor recarregue a pagina"
      );
    }
  },

  clearMemory() {
    expression = "";
  },

  evalCalc(expression) {
    try {
      return eval(expression);
    } catch (err) {
      console.log(err);
      alert("Não foi possível realizar o calculo");
    }
  },
};

Calc.init();
