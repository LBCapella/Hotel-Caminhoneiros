#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuApresentacao()
{
    printf("                **************************************************\n");
    printf("                *                                                *\n");
    printf("                *               HOTEL CALIFORNIA                 *\n");
    printf("                *                    Para                        *\n");
    printf("                *               Caminhoneiro(a)s                 *\n");
    printf("                *                                                *\n");
    printf("                **************************************************\n");
}

void caminhao() 
{
    printf("                       _____________________________________________________\n");
    printf("                      |                                                     |\n");
    printf("             _______  |                                                     |\n");
    printf("            / _____ | |                       BRAHMA                        |\n");
    printf("           / /(__) || |                                                     |\n");
    printf("  ________/ / |OO| || |                                                     |\n");
    printf(" |         |-------|| |                                                     |\n");
    printf("(|         |     -.|| |_______________________                              |\n");
    printf(" |  ____   \\       ||_________||____________  |             ____      ____  |\n");
    printf("/| / __ \\   |______||     / __ \\   / __ \\   | |            / __ \\    / __ \\ |\\\n");
    printf("\\|| /  \\ |_______________| /  \\ |_| /  \\ |__| |___________| /  \\ |__| /  \\ \\|/|\n");
    printf("   | () |                 | () |   | () |                  | () |    | () |\n");
    printf("    \\__/                   \\__/     \\__/                    \\__/      \\__/\n");
}

void limpaTela()
{
    system("@cls||clear");
}

void mensgBoasVindas()
{
    printf("========================================================================\n");
    printf("                             BOAS VINDAS                                \n");
    printf("Bem-vindo ao Hotel California Para Caminhoneiros! Desfrute de uma\n"
    "estadia luxuosa e exclusiva, especialmente projetada para caminhoneiros\n"
    "como voce. Nossa equipe esta empenhada em proporcionar uma experiencia\n"
    "unica e memoravel durante sua estadia.\n\n");
    system("pause");
    limpaTela();

    printf("========================================================================\n");
    printf("-> Localizacao estrategica: Situado em uma localizacao conveniente,\n" 
    "com facil acesso as principais rodovias e rotas de transporte.\n\n");

    printf("-> Instalacoes de luxo: Quartos espacosos,\n"
    "bem decorados e com amenidades de qualidade.\n\n");

    printf("->Servicos exclusivos para caminhoneiros: Estacionamento seguro,\n"
    "areas de descanso, lavanderia dedicada e opcoes de refeicoes especiais.\n\n");

    printf("-> Equipe dedicada: Hospitalidade calorosa e servico excepcional\n"
    "para garantir uma estadia agradavel e confortavel.\n");
    printf("========================================================================\n\n\n");

    printf("                               SEJA BEM VINDO(A)                          \n\n\n");

    printf("========================================================================\n");
    system("pause");
    limpaTela();
}

void menuEscolha()
{
    printf("========================================================================\n\n\n");

    printf("                      HOTEL CALIFORNIA CAMINHONEIROS                    \n\n\n");

    printf("========================================================================\n\n");

    printf("\t\t# Para acessar o mapa de quartos vagos e ocupados digite : 'A'\n");
    printf("\t\t# Para fazer reserva digite : 'B'\n");
    printf("\t\t# Para fazer checkin digite : 'C'\n");
    printf("\t\t# Para efetuar uma troca de quarto digite : 'D'\n");
    printf("\t\t# Para acessar o menu do restaurante digite : 'E'\n");
    printf("\t\t# Para fazer checkout digite : 'F'\n");
    printf("\t\t# Para Ver a lista de reservas digite : 'G'\n");
    printf("\t\t# Para sair do programa digite : 'H'\n");
}

typedef struct //typedef é usado para gerar um apelido ao novo tipo de variável, o apelido no caso é "reserva", assim não precisa usar sempre struct reserva
{
    char nome[50];
    int idade;
    char vulgo[50];
    char marcaCaminhao[50];
    char placa[7];
    int data;
    int numeroCel;
    int tipoQuarto;
    int andar, quarto;
} reserva;


void tabelaQuartos(int quartosPorAndar ,int primeiroAndar, int segundoAndar)
{
    const int max_Quartos = quartosPorAndar;
    const int max_Andares = segundoAndar - primeiroAndar + 1;

    char tabela[max_Andares][max_Quartos];

    for ( int i = 0; i < max_Quartos; i++)
    {
        for ( int j = 0; j < max_Andares; j++)
        {
            tabela[i][j] = '-';
        }
    }

    printf("Quartos ");
    for (int i = primeiroAndar; i <= segundoAndar; i++)
    {
        printf("  Andar:%d",i);
    }

    printf("\n");

    for (int i = 0; i < max_Quartos; i++)
    {
        printf("%d ->\t",i + 1);

        for (int j = 0; j < max_Andares; j++)
        {
            printf("    %c    ",tabela[i][j]);
        }
        printf("\n");
    }
}

int quartos (char nome[], int valor, int quartosPorAndar ,int primeiroAndar, int segundoAndar)
{
    printf("========================================================================\n\n\n");

    printf("                      HOTEL CALIFORNIA CAMINHONEIROS                    \n\n\n");

    printf("========================================================================\n\n");

    printf("NOME DO QUARTO:%s\n",nome );

    printf("PRECO: %d\n", valor);

    printf("Quartos do andar %d ao %d, segue o mapa (Quarto x Andar) de quartos e vagas disponíveis:\n\n",primeiroAndar, segundoAndar);

    tabelaQuartos(quartosPorAndar, primeiroAndar, segundoAndar);

    system("pause");
    limpaTela();
}

void casoA ()
{
    int detalhesQuarto;
    char nomeQuarto[50];
    int preco, quartosPorAndar;
    int primeiroAndar, segundoAndar;
    do
    {
        printf("========================================================================\n\n\n");

        printf("                      HOTEL CALIFORNIA CAMINHONEIROS                    \n\n\n");

        printf("========================================================================\n\n");

        printf("###########################################################################\n");
        printf("#        Quartos        ||     Preco|Noite      ||   Disponibilidade      #\n");
        printf("###########################################################################\n");
        printf("1.Suite Dream Road      ||       350,00 R$      ||        VAGAS           #\n");
        printf("2.Suite Diesel Oasis    ||       250,00 R$      ||        VAGAS           #\n");
        printf("3.Quarto Trucker's Haven||       180,00 R$      ||        VAGAS           #\n");
        printf("4.Quarto Midnight Drive ||       150,00 R$      ||        VAGAS           #\n");
        
        printf("Escolha uma para mais detalhes (0 para voltar ao menu): ");
        scanf("%d",&detalhesQuarto);
        getchar();

        if (detalhesQuarto == 0)
            break;
        
        switch (detalhesQuarto)
        {
        case 1:
            limpaTela();
            strcpy(nomeQuarto, "Suite Dream Road");
            preco = 350; 
            quartosPorAndar = 4;
            primeiroAndar = 10;
            segundoAndar = 12;
            quartos(nomeQuarto, preco, quartosPorAndar, primeiroAndar, segundoAndar);
            break;
        
        case 2:
            limpaTela();
            strcpy(nomeQuarto, "Suite Diesel Oasis");
            preco = 250; 
            quartosPorAndar = 5;
            primeiroAndar = 7;
            segundoAndar = 9;
            quartos(nomeQuarto, preco, quartosPorAndar, primeiroAndar, segundoAndar);
            break;

        case 3:
            limpaTela();
            strcpy(nomeQuarto, "Suite Diesel Oasis");
            preco = 180; 
            quartosPorAndar = 5;
            primeiroAndar = 4;
            segundoAndar = 6;
            quartos(nomeQuarto, preco, quartosPorAndar, primeiroAndar, segundoAndar);
            break;    
        
        case 4:
            limpaTela();
            preco = 150; 
            quartosPorAndar = 5;
            primeiroAndar = 1;
            segundoAndar = 3;
            quartos(nomeQuarto, preco, quartosPorAndar, primeiroAndar, segundoAndar);
            break;
            
        default:
            printf("Opcao digitada invalida, por favor tente novamente.");
            limpaTela();
            break;
        }
    } while (1);
    system("pause");
    limpaTela();
}

 //Definindo Constante para armazenar reservas:
 #define MAX_RESERVAS 100
 reserva reservas[MAX_RESERVAS];
 int numeroReserva = 0;


void casoB()
{
    reserva novaReserva;

    printf("========================================================================\n\n\n");

    printf("                      HOTEL CALIFORNIA CAMINHONEIROS                    \n\n\n");

    printf("========================================================================\n\n");

    printf("Preencha as informacoes abaixo:\n\n");

    printf("------------------------------------------------------------------------\n\n");
    
    printf("Digite seu nome: ");
    gets(novaReserva.nome);
    printf("Digite sua idade: ");
    scanf("%d",&novaReserva.idade);
    getchar();
    printf("Digite seu vulgo(Ex:Carreta Furacao): ");
    gets(novaReserva.vulgo);
    printf("Digite a marca do Caminhao: ");
    gets(novaReserva.marcaCaminhao);
    printf("Digite a placa do mesmo: ");
    gets(novaReserva.placa);
    printf("Digite a data que ira se hospedar: ");
    scanf("%d",&novaReserva.data);
    getchar();
    printf("Digite o numero para contato: ");
    scanf("%d",&novaReserva.numeroCel);
    getchar();
    printf("Agora diga quais dos quartos escolheu: ");
    scanf("%d",&novaReserva.quarto);
    getchar();
    printf("Diga o andar e o quarto(Ex: 1 3): ");
    scanf("%d,%d", &novaReserva.andar,&novaReserva.quarto);
    getchar();

    reservas[numeroReserva] = novaReserva; 
    numeroReserva++;
}

void casoG()
{
    printf("========================================================================\n\n\n");

    printf("                      HOTEL CALIFORNIA CAMINHONEIROS                    \n\n\n");

    printf("========================================================================\n\n");

    if (numeroReserva == 0)
    {
        printf("Nenhuma reserva encontrada...");
        system("pause");
    }

    else
    {
        printf("RESERVAS:\n");
        for (int i = 0; i < numeroReserva; i++)
        {
            reserva feitas = reservas[i];
            printf("Reserva numero: %d\n",i+1);
            printf("nome:%s\n",feitas.nome);
            printf("vulgo:%s\n",feitas.vulgo);
            printf("idade:%d\n",feitas.idade);
            printf("%d Andar, quarto %d\n",feitas.andar,feitas.quarto);
            printf("---------------------------------------------------------\n");
        }
        system("pause");
    }
    limpaTela();
}

int escolha(char opcao)
{
    switch (opcao)
    {
    case 'A':
    case 'a':
        casoA();
        break;

    case 'B':
    case 'b':
        casoB();
        break;

    case 'C':
    case 'c':
        /* code */
        break;

    case 'D':
    case 'd':
        /* code */
        break;

    case 'E':
    case 'e':
        /* code */
        break;

    case 'F':
    case 'f':
        /* code */
        break;

    case 'G':
    case 'g':
        casoG();
        break;    

    case 'H':
    case 'h':
        return 0;

    default:
        printf("Opcao digitada invalida, por favor tente novamente.\n");
        limpaTela();
        break;
    }
    return 1;
}

int main()
{
    char opcao;
    menuApresentacao();
    caminhao();
    printf("\n");
    mensgBoasVindas();

    do
    {
        menuEscolha();
        printf("\t\t# Digite a escolha: ");
        scanf("%c",&opcao);
        getchar();
        limpaTela();
    } while (escolha(opcao));
    
    return 0;
}
