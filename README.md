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
- [ ] obtém a raiz de um número racional 1
- [x] converte um número racional em um número real “double”
- [ ] converte um número double em um número racional 
- [ ] verifica se um número racional pode ser convertido em um número inteiro (eps = 0.00001)
- [x] escreve um número racional em um arquivo de texto no formato CSV 
- [ ] lê um arquivo racional de um arquivo de texto no formato CSV
- [ ] Utilize o Algoritmo recursivo de Euclides para encontrar o maior divisor comum dos números



### TAD para números complexos
#### métodos para:

##### Criação, destruição e cópia
- [x] criação de um número complexo
- [x] destruição de um número complexo
- [x] atribuir um número complexo a outro que já “existe” (isto é, que já foi “criado” antes)
- [x] copiar um número complexo em outro que não foi “criado” ainda

##### converter um número complexo de um “tipo” em outro:
- [ ] D_Complexo_pt em I_Complexo_pt (perigos: arredonde para o mais próximo)
- [ ] I_Complexo_pt em D_Complexo_pt (aqui o “perigo” é menor)
- [ ] D_Complexo_pt em R_Complexo_pt (também perigoso...)
- [ ] R_Complexo_pt em D_Complexo_pt (também perigoso...)
- [ ] R_Complexo_pt em I_Complexo_pt (também perigoso...)
- [ ] I_Complexo_pt em R_Complexo_pt (não há tantos perigos...)

##### Comparações complexas
- [x] verificação se o módulo de um número complexo é zero (admitindo uma tolerância eps = 0.00001 para o valor do módulo)
- [x] verificação se um número complexo é apenas real (admitindo uma tolerância eps = 0.00001 para o valor da parte imaginária)
- [x] verificação se um número complexo é apenas imaginário (admitindo uma tolerância eps = 0.00001 para a parte real)
- [x] comparar se um número complexo é igual, menor ou maior que outro (com relação ao seu módulo), considerando uma tolerância eps = 0.0001

##### Acessar/atribuir valor às componentes de um número complexo
- [x] retornar a parte real de um número complexo
- [x] retornar a parte imaginária de um número complexo
- [x] retornar a magnitude de um número complexo (módulo)
- [x] retornar a fase de um número complexo (ângulo)
- [x] atribuir novo valor à parte real de um número complexo representado por suas coordenadas
- [x] atribuir novo valor à parte imaginária de um número complexo representado por suas coordenadas
- [ ] atribuir novo valor à magnitude de um número complexo (módulo) mantendo seu ângulo
- [ ] atribuir novo valor à fase de um número complexo (ângulo) mantendo o seu módu

##### Operações
- [x] calcular o conjugado de um número complexo
- [x] somar, subtrair, dividir e multiplicar dois números complexos gerando um terceiro número
- [x] “acumular” somando (a += b) e multiplicando (a *= b) dois números complexos
- [x] fazer um método que executa uma das seis operações acima a operação pode ser “+”, “-”, “*”, “/”,”+=”, “*=”



### TAD para vetores
#### Métodos:

Crie um TAD vetores que possa operar sobre números inteiros, double **ou** complexos.

O TAD que você vai criar deve ter os seguintes “campos” / “atributos”:
* n = número atual de elementos;
* N = número máximo de elementos ;
* i = índice do elemento “atual”;
* elementos, propriamente ditos, acessíveis em sequência.

O número atual de elementos é a quantidade de elementos contidos (no momento) dentro do vetor.
Necessariamente é menor do que o “número máximo de elementos”.  

O número máximo de elementos deve ser aumentado (multiplicado por 2) se o número atual de elementos chegar a igualá-lo. Ele começa com um valor igual a 100.
Deve também ser reduzido pela metade se o número atual de elementos “n” baixar para menos do que N/4. Por exemplo, se n baixar de 4000, reduz-se N de 16000 para 8000.
O índice do elemento atual “i” é “incrementado de 0 até n-1” ao se percorrer os elementos do vetor do “início” para “fim” , e é “decrementado de n-1 até 0” ao se percorrer o vetor da posição “fim” até a posição “início”.  

- [x] criar o vetor
- [x] destruir o vetor
- [x] atribuir uma cópia do vetor a outro vetor já existente;
- [x] criar uma cópia do vetor, criando um novo vetor;
- [x] devolver o número atual de elementos;
- [x] devolver o número máximo de elementos;
- [x] devolver o índice do elemento atual;
- [x] devolver o primeiro elemento e posicionar “i” na primeira posição;
- [x] devolver o próximo elemento (posicionando “i” nesta posição);
- [x] devolver o elemento anterior (posicionando “i” nesta posição);
- [x] devolver o último elemento e posicionar “i” na última posição;
- [ ] devolver o elemento da i-ésima posição (lá posicionando o índice “i”);
- [ ] atribuir o valor “v” na i-ésima posição do vetor, posicionando ali o índice “i”;
- [ ] atribuir o valor “v” depois da última posição do vetor, incrementando o “número atual de elementos”;
- [ ] eliminar a i-ésima posição do vetor, devolvendo o seu valor atual e decrementando o “número atual de elementos”
- [ ] eliminar todos os elementos do vetor;
- [ ] obter o valor do elemento de maior módulo existente no vetor (e posicionar o índice atual naquela posição). Em caso de empate, qualquer uma das posições serve;
- [ ] obter o valor do elemento de menor módulo existente no vetor (e posicionar o índice atual naquela posição). Em caso de empate, qualquer uma das posições serve;
- [ ] determinar quantos dos elementos do vetor têm valor igual a “v” (considerar uma tolerância eps = 0.0001)
- [ ] devolver um vetor com as posições dos elementos que têm valor igual a “v” (considerar uma tolerância eps = 0.0001)
- [ ] ordenar os elementos do vetor de acordo com uma função “critério de comparação”.
    ▪ A função “critério” recebe dois elementos do vetor e os compara:
        se a = b, retorna “0”; se a < b, retorna -1; se a > b, retorna +1.
        A função “critério” é um dos argumentos deste método de ordenação;
- [ ] intercalar dois vetores ordenados, criando um novo vetor igualmente ordenado, usando uma função “critério” que igualmente um argumento deste método de intercalação;
- [ ] somar dois vetores de mesmo tamanho criando um novo vetor (C = A + B);
- [ ] multiplicar dois vetores (“produto interno”) gerando um valor “produto” (c = A . B)
- [ ] subtrair um vetor de outro vetor, criando um novo vetor; (C = A – B);
- [ ] multiplicar um vetor por um escalar, alterando os valores do vetor original (A = k * A)
- [ ] acumular um vetor B sobre um outro vetor A do mesmo tamanho, somando os elementos um-a-um (A = A+ B)
- [ ] determinar a média aritmética dos valores de um vetor
- [ ] determinar a variância dos valores de um vetor
- [ ] determinar o desvio padrão dos valores de um vetor (raiz quadrada da variância)
- [ ] determinar a mediana dos valores de um vetor (o valor que separa os 50% maiores dos 50%
menores. (referência https://pt.wikipedia.org/wiki/M%C3%A9dia) . Este algoritmo aparenta ser, enganosamente, fácil. (OBS: para números complexos há outros algoritmos e medidas mais importantes, principalmente na área de processamento de sinais)
    ◦ Uma implementação “burra”: ordena o vetor e pega o elemento central ou a média dos dois elementos centrais;
    ◦ uma implementação mais esperta é oferecida por Niklaus Wirth e uma implementação está disponível em http://ndevilla.free.fr/median/median/index.html . Lá há outras implementações igualmente disponíveis.



