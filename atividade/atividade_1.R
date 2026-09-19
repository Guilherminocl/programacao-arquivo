```r
# Exercício 1 - Temperatura corporal

temperatura <- as.numeric(readline("Digite a temperatura: "))

if (temperatura > 37.5) {
  print("Temperatura elevada")
} else {
  print("Temperatura normal")
}


# Exercício 2 - Idade

idade <- as.numeric(readline("Digite a idade: "))

if (idade >= 18) {
  print("Maior de idade")
} else {
  print("Menor de idade")
}


# Exercício 3 - Altura de uma planta

altura <- as.numeric(readline("Digite a altura da planta: "))

if (altura >= 20) {
  print("Planta desenvolvida")
} else {
  print("Planta ainda em crescimento")
}


# Exercício 4 - Velocidade de um animal

velocidade <- as.numeric(readline("Digite a velocidade: "))

if (velocidade > 10) {
  print("Alta velocidade")
} else {
  print("Baixa velocidade")
}


# Exercício 5 - Crescimento de uma população bacteriana

inicial <- as.numeric(readline("Digite a quantidade inicial: "))
final <- as.numeric(readline("Digite a quantidade final: "))

variacao <- final - inicial

print(variacao)

if (variacao > 0) {
  print("A população aumentou")
} else {
  print("A população não aumentou")
}


# Exercício 6 - Percentual de germinação

plantadas <- as.numeric(readline("Digite a quantidade plantada: "))
germinadas <- as.numeric(readline("Digite a quantidade germinada: "))

if (germinadas > plantadas) {
  print("Dado incorreto")
} else {
  percentual <- (germinadas / plantadas) * 100
  
  print(percentual)
  
  if (percentual >= 70) {
    print("Ótima germinação")
  } else if (percentual >= 55) {
    print("Germinação regular")
  } else if (percentual >= 40) {
    print("Germinação baixa")
  } else {
    print("Germinação muito baixa")
  }
}


# Exercício 7 - Média de crescimento

planta1 <- as.numeric(readline("Digite o crescimento da primeira planta: "))
planta2 <- as.numeric(readline("Digite o crescimento da segunda planta: "))

if (planta1 < 0 || planta2 < 0) {
  print("Dado incorreto")
} else {
  media <- (planta1 + planta2) / 2
  
  print(media)
  
  if (media >= 8) {
    print("Crescimento excelente")
  } else if (media >= 5) {
    print("Crescimento satisfatório")
  } else if (media >= 3) {
    print("Crescimento moderado")
  } else {
    print("Crescimento baixo")
  }
}
