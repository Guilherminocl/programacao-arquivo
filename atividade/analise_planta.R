

inicial <- as.numeric(readline("Altura inicial: "))
final <- as.numeric(readline("Altura final: ")) 
folhas <- as.numeric(readline("Folhas novas: "))
luz <- as.numeric(readline("Horas de luz: "))

umido <- readline("Solo muito umido? (sim/nao): ")
amarelas <- readline("Folhas amareladas? (sim/nao): ")
secas <- readline("Folhas secas? (sim/nao): ")


if (final < inicial) {
  print("Dados invalidos")
} else {
  
  crescimento <- final - inicial
  
  if (umido == "sim" && amarelas == "sim") {
    print("Atencao a irrigacao")
    
  } else if (crescimento < 5 && luz < 4) {
    print("Atencao a luminosidade")
    
  } else if (crescimento < 5 && secas == "sim") {
    print("Desenvolvimento comprometido")
    
  } else if (crescimento >= 10 && folhas >= 5 && luz >= 5 &&
             amarelas == "nao" && secas == "nao") {
    print("Condicao adequada")
    
  } else if (crescimento >= 5) {
    print("Desenvolvimento satisfatorio")
    
  } else {
    print("Desenvolvimento abaixo do esperado")
  }
}
