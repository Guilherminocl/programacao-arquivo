let bancoCookies = [];
let carrinho = [];

// ================= ADMIN =================

function adicionarCookie() {

    const nome = document.getElementById("inputNomeCookie").value.trim();
    const descricao = document.getElementById("inputDescricaoCookie").value.trim();
    const preco = parseFloat(document.getElementById("inputPrecoCookie").value);
    const mensagem = document.getElementById("mensagem");

    if (!nome || !descricao || isNaN(preco)) {
        mensagem.textContent = "Preencha corretamente!";
        mensagem.style.color = "red";
        return;
    }

    bancoCookies.push({
        id: Date.now(),
        nome,
        descricao,
        preco
    });

    mensagem.textContent = "Cookie cadastrada!";
    mensagem.style.color = "green";

    document.getElementById("inputNomeCookie").value = "";
    document.getElementById("inputDescricaoCookie").value = "";
    document.getElementById("inputPrecoCookie").value = "";

    renderizarCardapio();
}

function excluirCookie(id) {
    bancoCookies = bancoCookies.filter(c => c.id !== id);
    renderizarCardapio();
}


// ================= CARDÁPIO =================

function renderizarCardapio() {

    const cardapio = document.getElementById("cardapio");
    cardapio.innerHTML = "";

    bancoCookies.forEach(cookie => {

        let li = document.createElement("li");

        li.innerHTML = `
            <strong>${cookie.nome}</strong>
            <br>
            ${cookie.descricao}
            <br>
            R$ ${cookie.preco.toFixed(2)}
            <br><br>
            <button onclick="adicionarAoCarrinho(${cookie.id})">Adicionar</button>
            <button onclick="excluirCookie(${cookie.id})">Excluir</button>
        `;

        cardapio.appendChild(li);
    });
}


// ================= CARRINHO =================

function adicionarAoCarrinho(id) {

    let produto = bancoCookies.find(c => c.id === id);
    let item = carrinho.find(i => i.id === id);

    if (item) {
        item.quantidade++;
    } else {
        carrinho.push({
            id: produto.id,
            nome: produto.nome,
            preco: produto.preco,
            quantidade: 1
        });
    }

    renderizarCarrinho();
}

function renderizarCarrinho() {

    const lista = document.getElementById("listaCarrinho");
    lista.innerHTML = "";

    carrinho.forEach(item => {

        let li = document.createElement("li");

        li.innerHTML = `
            ${item.nome} 
            <br>
            R$ ${item.preco.toFixed(2)}
            <br>
            <button onclick="diminuir(${item.id})">➖</button>
            ${item.quantidade}
            <button onclick="aumentar(${item.id})">➕</button>
            <br>
            Subtotal: R$ ${(item.preco * item.quantidade).toFixed(2)}
        `;

        lista.appendChild(li);
    });

    atualizarTotal();
}

function aumentar(id) {
    let item = carrinho.find(i => i.id === id);
    item.quantidade++;
    renderizarCarrinho();
}

function diminuir(id) {
    let item = carrinho.find(i => i.id === id);
    item.quantidade--;

    if (item.quantidade <= 0) {
        carrinho = carrinho.filter(i => i.id !== id);
    }

    renderizarCarrinho();
}

function atualizarTotal() {
    let total = 0;
    carrinho.forEach(item => total += item.preco * item.quantidade);
    document.getElementById("totalCarrinho").textContent = total.toFixed(2);
}


// ================= WHATSAPP =================

function finalizarPedido() {

    if (carrinho.length === 0) {
        alert("Carrinho vazio!");
        return;
    }

    let mensagem = "🍪 *Novo Pedido* \n\n";

    carrinho.forEach(item => {
        mensagem += `${item.nome} x${item.quantidade} - R$ ${(item.preco * item.quantidade).toFixed(2)}\n`;
    });

    mensagem += `\nTotal: R$ ${document.getElementById("totalCarrinho").textContent}`;

    let numero = "5511999999999"; // COLOQUE SEU NÚMERO AQUI
    let url = `https://wa.me/${numero}?text=${encodeURIComponent(mensagem)}`;

    window.open(url, "_blank");
}