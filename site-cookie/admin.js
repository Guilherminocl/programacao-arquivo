firebase.initializeApp({
apiKey:"",
authDomain:"",
databaseURL:"",
projectId:""
});

const db = firebase.database();

db.ref("pedidos").on("value", snap=>{

const div = document.getElementById("pedidos");
div.innerHTML="";

snap.forEach(p=>{

const pedido = p.val();

div.innerHTML+=`
<div style="border:1px solid #ccc;padding:15px;margin:10px">

<h3>${pedido.nome}</h3>

<p>${pedido.telefone}</p>

<p>Status: ${pedido.status}</p>

<button onclick="mudarStatus('${p.key}','confirmado')">
Confirmar
</button>

</div>
`;

});

});

function mudarStatus(id,status){
db.ref("pedidos/"+id).update({status});
}