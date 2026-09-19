const firebaseConfig = {
apiKey:"",
authDomain:"",
databaseURL:"",
projectId:""
};

firebase.initializeApp(firebaseConfig);
const db = firebase.database();

const produtos = [
{nome:"Chocolate", preco:10},
{nome:"Tradicional", preco:8},
{nome:"Limão", preco:8}
];

let carrinho = [];

function carregarCardapio(){
const div = document.getElementById("cardapio");

produtos.forEach(prod => {

const card = document.createElement("div");
card.className="card";

card.innerHTML=`
<div>
<b>${prod.nome}</b><br>
R$ ${prod.preco.toFixed(2)}
</div>

<div>
<button onclick="add('${prod.nome}')">➕</button>
<button onclick="rem('${prod.nome}')">➖</button>
</div>
`;

div.appendChild(card);

});
}

function add(nome){
const prod = produtos.find(p=>p.nome===nome);
carrinho.push(prod);
renderCarrinho();
}

function rem(nome){
const index = carrinho.findIndex(p=>p.nome===nome);
if(index>-1) carrinho.splice(index,1);
renderCarrinho();
}

function renderCarrinho(){
const div = document.getElementById("carrinho");
div.innerHTML="";

carrinho.forEach(p=>{
div.innerHTML+=`<p>${p.nome} - R$ ${p.preco}</p>`;
});
}

function fazerPedido(){

const pedido = {
nome:document.getElementById("nome").value,
telefone:document.getElementById("telefone").value,
obs:document.getElementById("obs").value,
itens:carrinho,
status:"pendente",
data:Date.now()
};

db.ref("pedidos").push(pedido);

alert("Pedido enviado!");
}

carregarCardapio();