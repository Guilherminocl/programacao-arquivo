let casas = document.querySelectorAll('.casa');
let mensagem = document.querySelector('.mensagem');
let botaoReiniciar = document.querySelector('.botao-reiniciar');
let botaoAleatorio = document.querySelector('.botao-aleatorio');

let jogadorAtual = 'X';
let jogoAtivo = true;
let modoComputador = true; // true = jogador humano é X, computador é O

let tabuleiro = ['', '', '', '', '', '', '', '', ''];

let combinacoesVitoria = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6]
];

// Eventos
casas.forEach(function(casa) {
    casa.addEventListener('click', clicarNaCasa);
});

botaoReiniciar.addEventListener('click', reiniciarJogo);
if (botaoAleatorio) {
    botaoAleatorio.addEventListener('click', function() {
        modoComputador = !modoComputador;
        botaoAleatorio.textContent = modoComputador ? 'Modo: vs Computador' : 'Modo: 2 Jogadores';
        reiniciarJogo();
    });
}

// Quando clica em uma casa
function clicarNaCasa(event) {
    let casaClicada = event.target;
    let indexCasa = casaClicada.getAttribute('data-index');

    if (tabuleiro[indexCasa] !== '' || !jogoAtivo) {
        return;
    }

    tabuleiro[indexCasa] = jogadorAtual;
    casaClicada.textContent = jogadorAtual;

    verificarResultado();

    // Se modo contra computador estiver ativo e jogo ainda estiver ativo,
    // e for a vez do computador, faça a jogada dele com um pequeno atraso.
    if (jogoAtivo && modoComputador && jogadorAtual === 'O') {
        setTimeout(fazerJogadaComputador, 300);
    }
}

// Verifica vitória ou empate
function verificarResultado() {
    let venceu = false;

    for (let i = 0; i < combinacoesVitoria.length; i++) {
        let combinacao = combinacoesVitoria[i];

        let posicao1 = combinacao[0];
        let posicao2 = combinacao[1];
        let posicao3 = combinacao[2];

        let valor1 = tabuleiro[posicao1];
        let valor2 = tabuleiro[posicao2];
        let valor3 = tabuleiro[posicao3];

        if (valor1 === '' || valor2 === '' || valor3 === '') {
            continue;
        }

        if (valor1 === valor2 && valor2 === valor3) {
            venceu = true;
            break;
        }

    }

    if (venceu) {
        mensagem.textContent = 'Jogador ' + jogadorAtual + ' venceu!';
        jogoAtivo = false;
        return;
    }

    if (!tabuleiro.includes('')) {
        mensagem.textContent = 'Deu velha!';
        jogoAtivo = false;
        return;
    }

    trocarJogador();
}

// Troca jogador
function trocarJogador() {
    if (jogadorAtual === 'X') {
        jogadorAtual = 'O';
    } else {
        jogadorAtual = 'X';
    }

    mensagem.textContent = 'Vez do jogador ' + jogadorAtual;
}

// Reinicia o jogo
function reiniciarJogo() {
    tabuleiro = ['', '', '', '', '', '', '', '', ''];
    jogadorAtual = 'X';
    jogoAtivo = true;

    mensagem.textContent = 'Vez do jogador X';

    casas.forEach(function(casa) {
        casa.textContent = '';
    });
}

function jogadaAleatoria() {
    let casasDisponiveis = [];
    
    for (let i = 0; i < tabuleiro.length; i++) {
        if (tabuleiro[i] === '') {
            casasDisponiveis.push(i);
        }
    }
    
    if (casasDisponiveis.length === 0) {
        return;
    }
    
    let indexAleatorio = Math.floor(Math.random() * casasDisponiveis.length);
    let indexCasa = casasDisponiveis[indexAleatorio];
    
    tabuleiro[indexCasa] = 'O';
    casas[indexCasa].textContent = 'O';
    
    verificarResultado();
}

// IA usando Minimax (computador é 'O', humano é 'X')
function fazerJogadaComputador() {
    if (!jogoAtivo) return;

    let indice = melhorMovimento(tabuleiro);
    if (indice === -1) return;

    tabuleiro[indice] = 'O';
    casas[indice].textContent = 'O';

    verificarResultado();
}

function melhorMovimento(board) {
    // se só uma casa disponível, retorna ela
    let disponiveis = [];
    for (let i = 0; i < board.length; i++) if (board[i] === '') disponiveis.push(i);
    if (disponiveis.length === 0) return -1;

    let melhorScore = -Infinity;
    let movimento = -1;

    for (let i = 0; i < board.length; i++) {
        if (board[i] === '') {
            board[i] = 'O';
            let score = minimax(board, 0, false);
            board[i] = '';
            if (score > melhorScore) {
                melhorScore = score;
                movimento = i;
            }
        }
    }

    return movimento;
}

function minimax(board, depth, isMaximizing) {
    let resultado = checarVencedor(board);
    if (resultado !== null) {
        if (resultado === 'O') return 10 - depth;
        else if (resultado === 'X') return depth - 10;
        else return 0;
    }

    if (isMaximizing) {
        let melhor = -Infinity;
        for (let i = 0; i < board.length; i++) {
            if (board[i] === '') {
                board[i] = 'O';
                let score = minimax(board, depth + 1, false);
                board[i] = '';
                melhor = Math.max(melhor, score);
            }
        }
        return melhor;
    } else {
        let melhor = Infinity;
        for (let i = 0; i < board.length; i++) {
            if (board[i] === '') {
                board[i] = 'X';
                let score = minimax(board, depth + 1, true);
                board[i] = '';
                melhor = Math.min(melhor, score);
            }
        }
        return melhor;
    }
}

function checarVencedor(board) {
    for (let i = 0; i < combinacoesVitoria.length; i++) {
        let [a, b, c] = combinacoesVitoria[i];
        if (board[a] !== '' && board[a] === board[b] && board[b] === board[c]) {
            return board[a];
        }
    }

    if (!board.includes('')) return 'tie';
    return null;
}