var builder = WebApplication.CreateBuilder(args);

builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();
builder.Services.AddCors();

var app = builder.Build();

app.UseSwagger();
app.UseSwaggerUI();

app.UseCors(x =>
    x.AllowAnyOrigin()
     .AllowAnyHeader()
     .AllowAnyMethod()
);

var produtos = new List<Produto>();

app.MapGet("/", () => "API funcionando");

// GET
app.MapGet("/produtos", () =>
{
    return produtos;
});

// POST
app.MapPost("/produtos", (Produto produto) =>
{
    produto.Id = produtos.Count + 1;

    produtos.Add(produto);

    return Results.Ok(produto);
});

app.Run();

public class Produto
{
    public int Id { get; set; }

    public string Nome { get; set; } = "";

    public decimal Preco { get; set; }
}