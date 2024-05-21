#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o responsavel por cadastrar os usu�rios no sisitema
{
	//in�cio cria��o de variaveis/string
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final cria��o de variaveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string     
    
    strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
    
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
    fprintf(file,cpf); //Salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //Abre um arquivo no modo de inclus�o
    fprintf(file,","); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s",nome); //refere-se a string
    
    file = fopen(arquivo, "a"); //Abre um arquivo no modo de inclus�o
    fprintf(file,nome), //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //Abre um arquivo no modo de inclus�o
    fprintf(file,","); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s",sobrenome); //refere-se a string
    
    file = fopen(arquivo, "a"); //Abre um arquivo no modo de inclus�o
    fprintf(file,sobrenome); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //Abre um arquivo no modo de inclus�o
    fprintf(file,","); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s",cargo);//refere-se a string
    
    file = fopen(arquivo, "a"); //Abre um arquivo no modo de inclus�o
    fprintf(file,cargo); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    system("pause"); //pausa na p�gina de resposta do usu�rio
}

int consulta() //Fun��o responsavel pela consulta no sistema
{	
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
    //in�cio cria��o de variaveis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de variaveis/string
	printf("Digite o cpf a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //refere-se a string
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Cria o arquivo o "r" significa ler
	
	if(file == NULL) 
	{
	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //Mensagem dad� quando n�o encontra o arquivo proucurado
    }
    
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	
}
	
int main()
    {
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	
	     system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	printf("Escolha a op��o desejada do menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n"); 
	printf("\t4 - Sair do sistema\n\n");
	printf("Op��o:"); //Fim do menu
	
	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	system("cls"); //responsavel por limpar a tela
	
	
	switch(opcao)
	{
		case 1:
	    registro();
	    break;
	    
	    case 2:
	    consulta();
	    break;
	    
	    case 3:
	    deletar();
	    break;
	    
	    case 4:
	    printf("Obrigado por utilizar o sistema!\n");	
	    return 0;
		break;	
	    
	    default:
	    printf("Essa op��o n�o est� disponivel!\n");
	    system("pause");
	    break;
	}
   } 
    }
