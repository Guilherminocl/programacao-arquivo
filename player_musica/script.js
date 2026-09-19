let musica = document.querySelector('audio');

let botaoPlay = document.querySelector('.botao-pley');
let botaoPause = document.querySelector('.botao-pause');
let botaoVoltar = document.querySelector('.botao-voltar');
let botaoAvancar = document.querySelector('.botao-avancar');

let barra = document.querySelector('progress');
let barraContainer = document.querySelector('.barra');
let ponto = document.querySelector('.ponto');

let tempoDecorrido = document.querySelector('.inicio');
let tempoFinal = document.querySelector('.fim');

let nomeMusica = document.querySelector('.descricao h2');
let nomeArtista = document.querySelector('.descricao i');
let capa = document.querySelector('img');

// LISTA DE MÚSICAS
let musicas = [
    {
        titulo: 'Are You Ready',
        artista: 'Artista 1',
        arquivo: 'musicas/Are You Ready.mp3',
        imagem: 'imagens/capa.jfif'
    },
    {
        titulo: 'Musica 2',
        artista: 'Artista 2',
        arquivo: 'musicas/musica2.mp3',
        imagem: 'imagens/capa2.jpg'
    },
    {
        titulo: 'Musica 3',
        artista: 'Artista 3',
        arquivo: 'musicas/musica3.mp3',
        imagem: 'imagens/capa3.jpg'
    }
];

let indexMusica = 0;

// Eventos
botaoPlay.addEventListener('click', tocarMusica);
botaoPause.addEventListener('click', pausarMusica);
botaoVoltar.addEventListener('click', musicaAnterior);
botaoAvancar.addEventListener('click', proximaMusica);

musica.addEventListener('timeupdate', atualizarBarra);
musica.addEventListener('loadedmetadata', carregarDuracao);
musica.addEventListener('ended', proximaMusica);

barraContainer.addEventListener('click', clicarNaBarra);

// CARREGAR PRIMEIRA MÚSICA
carregarMusica(indexMusica);

function carregarMusica(index) {
    musica.src = musicas[index].arquivo;
    musica.load(); // IMPORTANTE

    nomeMusica.textContent = musicas[index].titulo;
    nomeArtista.textContent = musicas[index].artista;
    capa.src = musicas[index].imagem;

    barra.value = 0;
    ponto.style.left = '0%';
    tempoDecorrido.textContent = '0:00';
    tempoFinal.textContent = '0:00';
}

// PLAY
function tocarMusica() {
    musica.play();
    botaoPause.style.display = 'block';
    botaoPlay.style.display = 'none';
}

// PAUSE
function pausarMusica() {
    musica.pause();
    botaoPlay.style.display = 'block';
    botaoPause.style.display = 'none';
}

// ATUALIZA BARRA
function atualizarBarra() {
    if (musica.duration) {
        let porcentagem = (musica.currentTime / musica.duration) * 100;

        barra.value = porcentagem;
        ponto.style.left = porcentagem + '%';

        tempoDecorrido.textContent = segundosParaMinutos(Math.floor(musica.currentTime));
    }
}

// CARREGA DURAÇÃO TOTAL
function carregarDuracao() {
    tempoFinal.textContent = segundosParaMinutos(Math.floor(musica.duration));
}

// CONVERTER SEGUNDOS
function segundosParaMinutos(segundos) {
    let campoMinutos = Math.floor(segundos / 60);
    let campoSegundos = segundos % 60;

    if (campoSegundos < 10) {
        campoSegundos = '0' + campoSegundos;
    }

    return campoMinutos + ':' + campoSegundos;
}

// PRÓXIMA MÚSICA
function proximaMusica() {
    indexMusica++;

    if (indexMusica >= musicas.length) {
        indexMusica = 0;
    }

    carregarMusica(indexMusica);

    musica.play().then(() => {
        botaoPause.style.display = 'block';
        botaoPlay.style.display = 'none';
    }).catch(() => {
        botaoPlay.style.display = 'block';
        botaoPause.style.display = 'none';
    });
}

// MÚSICA ANTERIOR
function musicaAnterior() {
    indexMusica--;

    if (indexMusica < 0) {
        indexMusica = musicas.length - 1;
    }

    carregarMusica(indexMusica);

    musica.play().then(() => {
        botaoPause.style.display = 'block';
        botaoPlay.style.display = 'none';
    }).catch(() => {
        botaoPlay.style.display = 'block';
        botaoPause.style.display = 'none';
    });
}

// CLICAR NA BARRA
function clicarNaBarra(event) {
    let larguraBarra = barraContainer.clientWidth;
    let posicaoClique = event.offsetX;
    let porcentagem = posicaoClique / larguraBarra;

    if (musica.duration) {
        musica.currentTime = porcentagem * musica.duration;
    }
}