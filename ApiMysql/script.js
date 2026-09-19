
const api = "http://localhost:5062";
async function salvarProduto() {

    const nome = document.getElementById("nome").value;
    const preco = parseFloat(document.getElementById("preco").value);

    const produto = { nome, preco };

    const response = await fetch(`${api}/produtos`, {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify(produto)
    });

    console.log("STATUS:", response.status);

    if (!response.ok) {
        alert("Erro ao salvar no backend!");
        return;
    }

    document.getElementById("nome").value = "";
    document.getElementById("preco").value = "";

    carregarProdutos();
}
