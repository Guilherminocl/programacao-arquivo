let tabuleiro = document.querySelector('.tabuleiro');
let mensagem = document.querySelector('.mensagem');
let botaoReiniciar = document.querySelector('.botao-reiniciar');

let quantidadeLinhas = 8;
let quantidadeColunas = 8;
let quantidadeMinas = 10;

let casas = [];
let jogoAtivo = true;

// Eventos
botaoReiniciar.addEventListener('click', iniciarJogo);

// Inicia o jogo
iniciarJogo();

function iniciarJogo() {
    tabuleiro.innerHTML = '';
    casas = [];
    jogoAtivo = true;
    mensagem.textContent = 'Clique em uma casa para começar';

    criarCasas();
    posicionarMinas();
    calcularNumeros();
    desenharTabuleiro();
}

// Cria as casas do tabuleiro
function criarCasas() {
    for (let i = 0; i < quantidadeLinhas * quantidadeColunas; i++) {
        casas.push({
            index: i,
            mina: false,
            aberta: false,
            numero: 0
        });
    }
}

// Coloca minas aleatórias
function posicionarMinas() {
    let minasColocadas = 0;

    while (minasColocadas < quantidadeMinas) {
        let indexAleatorio = Math.floor(Math.random() * casas.length);

        if (!casas[indexAleatorio].mina) {
            casas[indexAleatorio].mina = true;
            minasColocadas++;
        }
    }
}

// Calcula quantas minas existem ao redor de cada casa
function calcularNumeros() {
    for (let i = 0; i < casas.length; i++) {
        if (casas[i].mina) {
            continue;
        }

        let vizinhos = pegarVizinhos(i);
        let quantidade = 0;

        for (let j = 0; j < vizinhos.length; j++) {
            if (casas[vizinhos[j]].mina) {
                quantidade++;
            }
        }

        casas[i].numero = quantidade;
    }
}

// Desenha o tabuleiro na tela
function desenharTabuleiro() {
    for (let i = 0; i < casas.length; i++) {
        let casa = document.createElement('div');
        casa.classList.add('casa');
        casa.setAttribute('data-index', i);

        casa.addEventListener('click', clicarNaCasa);

        tabuleiro.appendChild(casa);
    }
}

// Quando o jogador clica em uma casa
function clicarNaCasa(event) {
    if (!jogoAtivo) {
        return;
    }

    let casaClicada = event.target;
    let indexCasa = Number(casaClicada.getAttribute('data-index'));

    if (casas[indexCasa].aberta) {
        return;
    }

    abrirCasa(indexCasa);

    verificarVitoria();
}

// Abre uma casa
function abrirCasa(index) {
    let casa = casas[index];

    if (casa.aberta) {
        return;
    }

    casa.aberta = true;

    let elementoCasa = document.querySelector('[data-index="' + index + '"]');
    elementoCasa.classList.add('aberta');

    if (casa.mina) {
        elementoCasa.textContent = '💣';
        elementoCasa.classList.add('mina');
        mensagem.textContent = 'Você perdeu!';
        jogoAtivo = false;
        revelarMinas();
        return;
    }

    if (casa.numero > 0) {
        elementoCasa.textContent = casa.numero;
    }

    if (casa.numero === 0) {
        let vizinhos = pegarVizinhos(index);

        for (let i = 0; i < vizinhos.length; i++) {
            if (!casas[vizinhos[i]].aberta) {
                abrirCasa(vizinhos[i]);
            }
        }
    }
}

// Revela todas as minas quando perde
function revelarMinas() {
    for (let i = 0; i < casas.length; i++) {
        if (casas[i].mina) {
            let elementoCasa = document.querySelector('[data-index="' + i + '"]');
            elementoCasa.textContent = '💣';
            elementoCasa.classList.add('mina');
        }
    }
}

// Pega os vizinhos de uma casa
function pegarVizinhos(index) {
    let vizinhos = [];

    let linha = Math.floor(index / quantidadeColunas);
    let coluna = index % quantidadeColunas;

    for (let i = -1; i <= 1; i++) {
        for (let j = -1; j <= 1; j++) {
            if (i === 0 && j === 0) {
                continue;
            }

            let novaLinha = linha + i;
            let novaColuna = coluna + j;

            if (
                novaLinha >= 0 &&
                novaLinha < quantidadeLinhas &&
                novaColuna >= 0 &&
                novaColuna < quantidadeColunas
            ) {
                let novoIndex = novaLinha * quantidadeColunas + novaColuna;
                vizinhos.push(novoIndex);
            }
        }
    }

    return vizinhos;
}

// Verifica se o jogador venceu
function verificarVitoria() {
    let casasFechadas = 0;

    for (let i = 0; i < casas.length; i++) {
        if (!casas[i].aberta) {
            casasFechadas++;
        }
    }

    if (casasFechadas === quantidadeMinas && jogoAtivo) {
        mensagem.textContent = 'Parabéns! Você venceu!';
        jogoAtivo = false;
    }
}