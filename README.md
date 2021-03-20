# TEP-Assignment

## Implementações

### TAD para números racionais
#### Métodos:
- [x] cria um número racional
- [x] destrói um número racional
- [x] copia um número racional em outro número racional
- [x] compara dois números racionais
- [x] verifica se dois números racionais são equivalentes
- [x] verifica se o denominador é zero (x/0)
- [x] verifica se o número é zero (0/x)
- [x] verifica se ambos (numerador e denominador) são zero (0/0)
- [x] soma dois racionais, gerando um terceiro (c = a+b)
- [x] acumula um racional “b” a um primeiro racional “a” ( a += b)
- [x] subtrai dois racionais, gerando um terceiro
- [x] multiplica dois racionais, gerando um terceiro
- [x] multiplica um racional “b” a um primeiro racional “a” ( a *= b)
- [x] divide dois racionais, gerando um terceiro
- [x] obtém o quadrado de um número racional
- [  ] obtém a raiz de um número racional 1
- [x] converte um número racional em um número real “double”
- [  ] converte um número double em um número racional 
- [  ] verifica se um número racional pode ser convertido em um número inteiro (eps = 0.00001)
- [x] escreve um número racional em um arquivo de texto no formato CSV 
- [  ] lê um arquivo racional de um arquivo de texto no formato CSV
- [  ] Utilize o Algoritmo recursivo de Euclides para encontrar o maior divisor comum dos números



### TAD para números complexos
#### métodos para:

##### Criação, destruição e cópia
- [x] criação de um número complexo
- [x] destruição de um número complexo
- [  ] atribuir um número complexo a outro que já “existe” (isto é, que já foi “criado” antes)
- [  ] copiar um número complexo em outro que não foi “criado” ainda

##### converter um número complexo de um “tipo” em outro:
- [  ] D_Complexo_pt em I_Complexo_pt (perigos: arredonde para o mais próximo)
- [  ] I_Complexo_pt em D_Complexo_pt (aqui o “perigo” é menor)
- [  ] D_Complexo_pt em R_Complexo_pt (também perigoso...)
- [  ] R_Complexo_pt em D_Complexo_pt (também perigoso...)
- [  ] R_Complexo_pt em I_Complexo_pt (também perigoso...)
- [  ] I_Complexo_pt em R_Complexo_pt (não há tantos perigos...)

##### Comparações complexas
- [  ] verificação se o módulo de um número complexo é zero (admitindo uma tolerância eps = 0.00001 para o valor do módulo)
- [x] verificação se um número complexo é apenas real (admitindo uma tolerância eps = 0.00001 para o valor da parte imaginária)
- [x] verificação se um número complexo é apenas imaginário (admitindo uma tolerância eps = 0.00001 para a parte real)
- [  ] comparar se um número complexo é igual, menor ou maior que outro (com relação ao seu módulo), considerando uma tolerância eps = 0.0001
- [  ] comparar se um número complexo é igual, menor ou maior que outro (com relação ao seu ângulo), considerando uma tolerância eps = 0.0001

##### Acessar/atribuir valor às componentes de um número complexo
- [x] retornar a parte real de um número complexo
- [x] retornar a parte imaginária de um número complexo
- [x] retornar a magnitude de um número complexo (módulo)
- [x] retornar a fase de um número complexo (ângulo)
- [x] atribuir novo valor à parte real de um número complexo representado por suas coordenadas
- [x] atribuir novo valor à parte imaginária de um número complexo representado por suas coordenadas
- [  ] atribuir novo valor à magnitude de um número complexo (módulo) mantendo seu ângulo
- [  ] atribuir novo valor à fase de um número complexo (ângulo) mantendo o seu módu

##### Operações
- [  ] calcular o conjugado de um número complexo
- [  ] somar, subtrair, dividir e multiplicar dois números complexos gerando um terceiro número
- [  ] “acumular” somando (a += b) e multiplicando (a *= b) dois números complexos
- [  ] fazer um método que executa uma das seis operações acima a operação pode ser “+”, “-”, “*”, “/”,”+=”, “*=”
