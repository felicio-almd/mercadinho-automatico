#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define estTotal 5

// erro no faturamento

int mostrarProdutos(int prod1, int prod2, int prod3, int prod4, int prod5, float faturamento);


void limpartela() { // função utilizada para limpar a tela do terminal //
  system("cls"); 
//system("clear");    se for rodar este programa em linux
}

void bemVindos() {    // funcao para mostrar a tela de boas vindas para novos clientes
  char enter;
  printf("\n\n\n\n\nSEJAM BEM VINDOS AO MERCADINHO, EM QUE POSSO LHES AJUDAR?");
  printf("\n\n\n\n       Digite ENTER para ver o Catalogo...");
  scanf("%c", &enter);
}

int lerOpcao() {    // funcao para ler a opcao que a opção que o cliente selecionar ao ver o catalogo e decidir o que quiser //
  int op;
  printf("Digite sua opcao(de 1 a 7): ");
  scanf("%d", &op);
  if (op >= 1 && op <= 7) {       // a funcao so funciona se for escolhido alguma das opções validas mostradas no catalogo
    return op;
  } else {                    // caso o numero for invalido vai imprimir e retornar a mesma funcao ate ser digitado um correto
    printf("Digite um numero valido!\n");
    lerOpcao();
  }
}

void outracompra(int prod1, int prod2, int prod3, int prod4, int prod5, float faturamento){       // funcao para realizar uma nova compra no mercado caso seja selecionado para voltar a tela inicial dos produtos
  char comprardnv;                                                                                 // foi utilizado os parametros dos produtos e do faturamento total da compra porque eles modificam a cada compra
    printf("\n\nGostaria de realizar outra compra em nosso Mercado? ( S para sim / N para nao )\n");      
    scanf(" %c", &comprardnv);
    if(comprardnv == 'S' || comprardnv == 's'){             // se for digitado s a funcao limpa a tela e retorna para a tela inicial onde mostra o catalogo
      limpartela();
      mostrarProdutos(prod1, prod2, prod3, prod4, prod5, faturamento);      // ao retornar a funcao mostrar produtos, usa os parametros dos produtos e do faturamento
    }
    else if (comprardnv == 'N' || comprardnv == 'n'){       // se for digitado N a funcao ira finalizar a maquina mostrando o estoque e o faturamento da loja pós as compras
      limpartela();
      printf("\n\nMaquina Finalizada!\n");
      printf("\n\nObrigado por comprar conosco!\n\n\n\n");
      printf("\n\nESTOQUE TOTAL DOS PRODUTOS DA LOJA:\n\n");
      printf("Gulao ....................... %d",prod1);
      printf("\nCoca Cola ................... %d",prod2);
      printf("\nSalgado Frito ............... %d",prod3);
      printf("\nBolacha Danix ............... %d",prod4);
      printf("\nLimonada (Jarra) ............ %d",prod5);
      printf("\n\nFATURAMENTO TOTAL DAS COMPRAS NO MERCADO: R$%.2f \n\n", faturamento);
    }
    else {                                    // se nao for digitado s ou n mostra opcao invalida e volta na funcao outra compra para repetir essa funcao outracompra.
      limpartela();
      printf("Operacao Invalida\n");
      outracompra(prod1, prod2, prod3, prod4, prod5, faturamento);
    }
}

float darnotas(float contEntrada, float valor, float troco, int prod1, int prod2, int prod3, int prod4, int prod5, float faturamento){ 
  troco+=0.0001;          // essa funcao darnotas dara o troco em notas ou moedas para cada valor colocado na hora de comprar, os parametros usados sao a contagem de entrada que eh usada na funcao abaixo
  if(troco>=100){         // alem delas usa o valor, troco, faturamento e os produtos que mudam a cada compra realizada
    printf("R$100,00\n");
    troco-=100;
    darnotas(contEntrada, valor, troco, prod1, prod2, prod3, prod4, prod5, faturamento);
  }
  else if(troco>=50){
    printf("R$50,00\n");
    troco-=50;
    darnotas(contEntrada, valor, troco, prod1, prod2, prod3, prod4, prod5, faturamento);
  }
  else if(troco>=20){
    printf("R$20,00\n");
    troco-=20;
    darnotas(contEntrada, valor, troco, prod1, prod2, prod3, prod4, prod5, faturamento);
  }
  else if(troco>=10){
    printf("R$10,00\n");
    troco-=10;
    darnotas(contEntrada, valor, troco, prod1, prod2, prod3, prod4, prod5, faturamento);
  }
  else if(troco>=5){
    printf("R$5,00\n");
    troco-=5;
    darnotas(contEntrada, valor, troco, prod1, prod2, prod3, prod4, prod5, faturamento);
  }
  else if(troco>=2){
    printf("R$2,00\n");
    troco-=2;
    darnotas(contEntrada, valor, troco, prod1, prod2, prod3, prod4, prod5, faturamento);
  }
  else if(troco>=1){
    printf("R$1,00\n");
    troco-=1;
    darnotas(contEntrada, valor, troco, prod1, prod2, prod3, prod4, prod5, faturamento);
  }
  else if(troco>=0.50){
    printf("R$0,50\n");
    troco-=0.50;
    darnotas(contEntrada, valor, troco, prod1, prod2, prod3, prod4, prod5, faturamento);
  }
  else if(troco>=0.25){
    printf("R$0,25\n");
    troco-=0.25;
    darnotas(contEntrada, valor, troco, prod1, prod2, prod3, prod4, prod5, faturamento);
  }
  else if(troco>=0.10){
    printf("R$0,10\n");
    troco-=0.10;
    darnotas(contEntrada, valor, troco, prod1, prod2, prod3, prod4, prod5, faturamento);
  }
  else if(troco>=0.05){
    printf("R$0,05\n");
    troco-=0.05;
    darnotas(contEntrada, valor, troco, prod1, prod2, prod3, prod4, prod5, faturamento);
  }
  else if(troco>=0.01){
    printf("R$0,01\n");
    troco-=0.01;
    darnotas(contEntrada, valor, troco, prod1, prod2, prod3, prod4, prod5, faturamento);
  }
  else if(troco<0.01){          // a cada else ou if sera da o valor do troco ate que nao tenha que ser entregado nenhum troco para pessoa
    outracompra(prod1, prod2, prod3, prod4, prod5, faturamento);      // assim que acabar de dar troco volta na funcao de saber se a pessoa quer novamente
  }
}

float dartroco(float contEntrada, float valor, int prod1, int prod2, int prod3, int prod4, int prod5, float faturamento) {     
  float troco, entrada = 0;       // nessa funcao mostra a tela para ser dado o troco e entrada seria o dinheiro que a pessoa coloca na maquina
  printf("\nQuantos R$ deseja inserir na Maquina?\n");              // os parametros sao a contagem de entrada que muda a cada compra feita aumentando o faturamento, o valor significa cada valor de produto
  scanf("%f", &entrada);              
  contEntrada+=entrada;                           
  if(contEntrada==valor){                                       // essa parte serve para mostrar que nao tem troco se o dinheiro colocado for igual o valor do produto
    limpartela();
    printf("\n\nO valor inserido foi de R$%.2f",contEntrada);                   
    printf("\n\nPagamento Concluido. Sem troco.\n\n");
    outracompra(prod1, prod2, prod3, prod4, prod5, faturamento);     // retorna para perguntar se quer comprar novamente
  }
  else if (contEntrada > valor) {                           // se o dinheiro colocado for maior que o valor chama essa funcao para dar o troco usando a funcao darnotas que foi feita acima
    troco = contEntrada - valor;
    limpartela();
    printf("\n\nO valor inserido foi de R$%.2f",contEntrada);
    printf("\nSeu troco total e de: R$%.2f \n\n", troco);
    printf("Pegue seu troco na Maquina.\n");
    darnotas(contEntrada, valor, troco, prod1, prod2, prod3, prod4, prod5, faturamento);  // aqui retorna a funcao darnotas para dar o troco
  } else {
    printf("Valor inserido insuficiente.\n");
    printf("Insira o restante do pagamento..\n");
    dartroco(contEntrada, valor, prod1, prod2, prod3, prod4, prod5, faturamento);    // se faltar dinheiro ira pedir para por mais dinheiro na maquina e dar o troco depois do dinheiro colocado
  }
}

int realizarCompra(int opcao, int prod1, int prod2, int prod3, int prod4, int prod5, float faturamento) {
  limpartela();
  float valor = 0, troco, contEntrada = 0;
  switch (opcao) {
  case 1:
    if (prod1 > 0) {
      printf("\n\nVoce escolheu comprar um gulao.\nValor: R$3,50\n");
      prod1--;
      valor = 3.50;
      faturamento += 3.50;
      troco = dartroco(contEntrada, valor, prod1, prod2, prod3, prod4, prod5, faturamento);

    } else if (prod1 == 0) {
      printf("Sem estoque desse produto.\n\n");
      outracompra(prod1, prod2, prod3, prod4, prod5, faturamento);
    }
    break;
  case 2:
    if (prod2 > 0) {
      printf("Voce escolheu comprar uma Coca Cola.\nValor: R$5,00\n");
      prod2--;
      valor = 5.00;
      faturamento += 5.00;
      troco = dartroco(contEntrada, valor, prod1, prod2, prod3, prod4, prod5, faturamento);

    } else if (prod2 == 0) {
      printf("Sem estoque desse produto.");
      outracompra(prod1, prod2, prod3, prod4, prod5, faturamento);
    }
    break;
  case 3:
    if (prod3 > 0) {
      printf("Voce escolheu comprar um Salgado frito.\nValor: R$6,50\n");
      prod3--;
      valor = 6.50;
      faturamento += 6.50;
      troco = dartroco(contEntrada, valor, prod1, prod2, prod3, prod4, prod5, faturamento);

    } else if (prod3 == 0) {
      printf("Sem estoque desse produto.");
      outracompra(prod1, prod2, prod3, prod4, prod5, faturamento);
    }
    break;
  case 4:
    if (prod4 > 0) {
      printf("Voce escolheu comprar uma Danix.\nValor: R$3,00\n");
      prod4--;
      valor = 3.00;
      faturamento += 3.00;
      troco = dartroco(contEntrada, valor, prod1, prod2, prod3, prod4, prod5, faturamento);

    } else if (prod4 == 0) {
      printf("Sem estoque desse produto.");
      outracompra(prod1, prod2, prod3, prod4, prod5, faturamento);
    }
    break;
  case 5:
    if (prod5 > 0) {
      printf("Voce escolheu comprar uma Limonada (Jarra).\nValor: R$8,40\n");
      prod5--;
      valor = 8.40;
      faturamento += 8.40;
      troco = dartroco(contEntrada, valor, prod1, prod2, prod3, prod4, prod5, faturamento);

    } else if (prod5 == 0) {
      printf("Sem estoque de Limonada.");
      outracompra(prod1, prod2, prod3, prod4, prod5, faturamento);
    }
    break;
  case 6:
    limpartela();
    printf("\n\nESTOQUE TOTAL DOS PRODUTOS DA LOJA:\n\n");
    printf("Gulao ....................... %d",prod1);
    printf("\nCoca Cola ................... %d",prod2);
    printf("\nSalgado Frito ............... %d",prod3);
    printf("\nBolacha Danix ............... %d",prod4);
    printf("\nLimonada (Jarra) ............ %d",prod5);
    printf("\n\nFATURAMENTO TOTAL DAS COMPRAS NO MERCADO: R$%.2f \n", faturamento);
    outracompra(prod1, prod2, prod3, prod4, prod5, faturamento);
    break;
  case 7:
    limpartela();
    printf("\n\nMaquina Finalizada!\n");
    printf("\n\nObrigado por comprar conosco!\n\n\n\n");
    printf("\n\nESTOQUE TOTAL DOS PRODUTOS DA LOJA:\n\n");
    printf("Gulao ....................... %d",prod1);
    printf("\nCoca Cola ................... %d",prod2);
    printf("\nSalgado Frito ............... %d",prod3);
    printf("\nBolacha Danix ............... %d",prod4);
    printf("\nLimonada (Jarra) ............ %d",prod5);
    printf("\n\nFATURAMENTO TOTAL DAS COMPRAS NO MERCADO: R$%.2f \n", faturamento);
    break;
  }
}


int mostrarProdutos(int prod1, int prod2, int prod3, int prod4, int prod5, float faturamento) {
  limpartela();
  printf("\n\n\n        BEM  VINDOS AO MERCADINHO\n\n");
  printf("+-------------------Produtos-------------------+\n");
  printf("|  1 - Gulao...........................R$3,50  |\n");
  printf("|  2 - Coca Cola.......................R$5,00  |\n");
  printf("|  3 - Salgado Frito...................R$6,50  |\n");
  printf("|  4 - Bolacha Danix...................R$3,00  |\n");
  printf("|  5 - Limonada (Jarra)................R$8,40  |\n");
  printf("+------------------MAIS OPCOES-----------------+\n");
  printf("|  6 - Estoque / Faturamento                   |\n");
  printf("|  7 - Finalizar                               |\n");
  printf("+----------------------------------------------+\n\n\n");
  int opcao = lerOpcao();
  realizarCompra(opcao, prod1, prod2, prod3, prod4, prod5, faturamento);
}


int main() {
  int prod1, prod2, prod3, prod4, prod5;
  float faturamento = 0;
  prod1 = prod2 = prod3 = prod4 = prod5 = estTotal;
  bemVindos();
  mostrarProdutos(prod1, prod2, prod3, prod4, prod5, faturamento);
}
