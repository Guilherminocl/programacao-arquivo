function adicionarTarefa() {

    //recebe valor do input do usuário
    const inputTarefa = document.getElementById("inputTarefa");
    let tarefa = inputTarefa.value.trim();

    const mensagem =  document.getElementById("mensagem");

    if (tarefa == "") {
        //mensagem de erro
        let mensagemErro = "Campo vazio!";
        mensagem.textContent = mensagemErro;

    } else {
        //cria novo item (li) e insere na (lista ul)
        const listaTarefas = document.getElementById("listaTarefas");
        let novaTarefa = document.createElement("li");
        novaTarefa.textContent = tarefa;
        listaTarefas.appendChild(novaTarefa);

        //mensagem de tarefa adicionada com sucesso
        let mensagemSucesso = "Tarefa adicionada com sucesso!";
        mensagem.textContent = mensagemSucesso;
    }

    //limpa o input do uusário
    inputTarefa.value = "";



}