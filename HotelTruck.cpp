//VDC-AtivXX - Hotel
//Carlos Gouveia, Kauã Cordeiro, Luan Capella, Pedro Gabriel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bannerHotel()
{
    printf("========================================================================\n\n\n");
    printf("                      HOTEL CALIFORNIA CAMINHONEIROS                    \n\n\n");
    printf("========================================================================\n\n");
}

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
    bannerHotel();

    printf("\t# Para acessar a lista de quartos e o mapa do hotel digite : 'A'\n");
    printf("\t# Para fazer reserva digite : 'B'\n");
    printf("\t# Para fazer checkin digite : 'C'\n");
    printf("\t# Para efetuar uma troca de quarto digite : 'D'\n");
    printf("\t# Para acessar o menu do restaurante digite : 'E'\n");
    printf("\t# Para fazer checkout digite : 'F'\n");
    printf("\t# Para Ver a lista de reservas digite : 'G'\n");
    printf("\t# Para sair do programa digite : 'H'\n");
}

typedef struct //typedef é usado para gerar um apelido ao novo tipo de variável, o apelido no caso é "reserva", assim não precisa usar sempre struct reserva
{
    char nome[50];
    int idade;
    char vulgo[100];
    char marcaCaminhao[50];
    char placa[10];
    int cpf;
    int numeroCel;
    int andar, quarto;
} reserva;

//Definindo Constante para armazenar reservas:
 #define MAX_RESERVAS 280
 reserva reservas[MAX_RESERVAS];
 int numeroReserva = 0;
 reserva checkIN[MAX_RESERVAS];


void tabelaQuartos()
{
    const int MAX_ANDARES = 21;
    const int MAX_QUARTOS = 14;

    char tabela[MAX_ANDARES][MAX_QUARTOS];
    
    int i, j;

    for (i = 0; i < MAX_ANDARES; i++) {
        for (j = 0; j < MAX_QUARTOS; j++) {
            tabela[i][j] = '.';
        }
    }

    for ( i = 0; i < numeroReserva; i++)
    {
        reserva c = checkIN[i];
        reserva r = reservas[i];
        tabela[r.andar][r.quarto - 1] = 'R';
        if (c.andar == r.andar && c.quarto == r.quarto)
        {
            tabela[c.andar][c.quarto - 1] = 'O';
        }
        
    }
    

    printf("\tMapa dos quartos:\n\n");

    printf("   ");
    for (j = 0; j < 14; j++) {
        printf("%2d ", j + 1);
    }
    printf("\n");

    for (i = MAX_ANDARES - 1 ; i > 0; i--) {
        printf("%2d ", i);
        for (j = 0; j < MAX_QUARTOS; j++) {
            printf("%2c ", tabela[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void quartos (char nome[], int valor,int primeiroAndar, int segundoAndar)
{
    bannerHotel();

    printf("NOME DO QUARTO:%s\n",nome );

    printf("PRECO: %d\n", valor);

    printf("Possui quartos do andar %d ao %d\n",primeiroAndar,segundoAndar);

    tabelaQuartos();

    system("pause");
    limpaTela();
}

void casoA ()
{
    int detalhesQuarto;
    char nomeQuarto[50];
    int preco;
    int primeiroAndar, segundoAndar;
    do
    {
        bannerHotel();

        printf("###########################################################################\n");
        printf("#        Quartos        ||     Preco|Noite      ||   Disponibilidade      #\n");
        printf("###########################################################################\n");
        printf("1.Suite Dream Road      ||       350,00 R$      ||        VAGAS           #\n");
        printf("2.Suite Diesel Oasis    ||       250,00 R$      ||        VAGAS           #\n");
        printf("3.Quarto Trucker's Haven||       180,00 R$      ||        VAGAS           #\n");
        printf("4.Quarto Midnight Drive ||       150,00 R$      ||        VAGAS           #\n");
        printf("5.Ver o mapa de quartos, vazios e vagos do Hotel.                         #\n");
        
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
            primeiroAndar = 16;
            segundoAndar = 20;
            quartos(nomeQuarto, preco, primeiroAndar, segundoAndar);
            break;
        
        case 2:
            limpaTela();
            strcpy(nomeQuarto, "Suite Diesel Oasis");
            preco = 250; 
            primeiroAndar = 11;
            segundoAndar = 15;
            quartos(nomeQuarto, preco, primeiroAndar, segundoAndar);
            break;

        case 3:
            limpaTela();
            strcpy(nomeQuarto, "Suite Diesel Oasis");
            preco = 180; 
            primeiroAndar = 6;
            segundoAndar = 10;
            quartos(nomeQuarto, preco, primeiroAndar, segundoAndar);
            break;    
        
        case 4:
            limpaTela();
            preco = 150; 
            primeiroAndar = 1;
            segundoAndar = 5;
            quartos(nomeQuarto, preco, primeiroAndar, segundoAndar);
            break;
            
        case 5:
        	limpaTela();
        	tabelaQuartos();
        	system("pause");
        	limpaTela();
        	break;
            
        default:
            printf("\nOpcao digitada invalida, por favor tente novamente.\n\n");
            system("pause");
            limpaTela();
            break;
        }
    } while (1);
    limpaTela();
}

void casoB()
{
    reserva novaReserva;

    bannerHotel();

    printf("Preencha as informacoes abaixo:\n\n");

    printf("------------------------------------------------------------------------\n\n");
    
    printf("Digite seu nome: ");
    fgets(novaReserva.nome, sizeof(novaReserva.nome), stdin);

    printf("Digite sua idade: ");
    scanf("%d", &novaReserva.idade);
    getchar();

    printf("Digite seu vulgo(Ex:Carreta Furacao): ");
    fgets(novaReserva.vulgo, sizeof(novaReserva.vulgo), stdin);

    printf("Digite a marca do Caminhao: ");
    fgets(novaReserva.marcaCaminhao, sizeof(novaReserva.marcaCaminhao), stdin);

    printf("Digite a placa do mesmo: ");
    fgets(novaReserva.placa, sizeof(novaReserva.placa), stdin);

    printf("Digite o cpf que ira se hospedar: ");
    scanf("%d", &novaReserva.cpf);
    getchar();

    printf("Digite o numero para contato: ");
    scanf("%d", &novaReserva.numeroCel);
    getchar();

    int andarValido = 0;

    while(!andarValido)
    {
        printf("Diga o andar e o quarto(Ex: 1 3): ");
        scanf("%d %d", &novaReserva.andar, &novaReserva.quarto);
        getchar();

        if (novaReserva.andar < 1 || novaReserva.andar > 20) 
        {
            printf("\nAndar invalido! Tente novamente!\n");
            system("pause");
            limpaTela();
        } 
        
        else if (novaReserva.quarto < 1 || novaReserva.quarto > 14) 
        {
            printf("\nQuarto invalido! Tente novamente!\n");
            system("pause");
            limpaTela();
        } 
        
        else 
        {
            andarValido = 1; // Valor de andar/quarto válido, sai do loop
        }
    }

    reservas[numeroReserva] = novaReserva; 
    numeroReserva++;

    printf("\nReserva cadastrada com sucesso!\n");
    printf("===============================================\n");
    printf("Pressione Enter para voltar ao menu principal...");
    getchar();
    limpaTela();
    
}

void casoG()
{
    bannerHotel();

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
            printf("CPF:%d\n",feitas.cpf);
            printf("%d Andar, quarto %d\n",feitas.andar,feitas.quarto);
            printf("---------------------------------------------------------\n");
        }
        system("pause");
    }
    limpaTela();
}



int casoC()
{
    char simNao;

    while (1)
    {
        bannerHotel();
        printf("Para efetuar o Checkin e' necessario ja possuir uma reserva.\n"
               "Caso ainda nao tenha feito, por favor volte para o menu e efetue a mesma.\n");
        printf("Caso ja tenha reserva, digite 'S'. Caso contrario, digite 'N': ");
        
        scanf(" %c", &simNao);
        getchar();
        
        limpaTela();

        if (simNao == 'N' || simNao == 'n')
        {
            return 0;
        }
        else if (simNao == 'S' || simNao == 's')
        {
            if (numeroReserva == 0)
            {
                printf("Nenhuma reserva encontrada...\n"
                        "Pressione ENTER para voltar ao menu e efetuar a reserva.");
                getchar();
                limpaTela();
                return 0;
            }

            else
                break;
        }

        else
        {
            printf("Comando invalido, tente novamente!\n");
            limpaTela();
        }
    }
    
    int verificaCpf;
    reserva checkin;
    int numeroCheckIN = -1; //para indicar que nenhuma reserva foi encontrada.
    
    while (numeroCheckIN == -1)
    {
        bannerHotel();
        printf("Digite o numero do CPF feito na reserva: ");
        scanf("%d", &verificaCpf);
        getchar();
        limpaTela();

        for (int i = 0; i < numeroReserva; i++)
        {
            checkin = reservas[i];
            checkIN[i] = checkin;

            if (verificaCpf == checkin.cpf)
            {
                numeroCheckIN = i;
                break;
            }
        }

        if (numeroCheckIN == -1)
        {
            printf("\nCPF invalido, tente novamente!\n");
            getchar();
            limpaTela();
            return 0;
        }
    }
    
    bannerHotel();
    printf("Muito bem, encontramos seu CPF na reserva, senhor(a) %s!\n", checkin.nome);
    
    while (1)
    {
        printf("Você gostaria de efetuar o Check-in? (S para sim, N para nao): ");
        scanf(" %c", &simNao);
        getchar();

        if (simNao == 'N' || simNao == 'n')
        {
            printf("\nPois bem, estaremos retirando a sua reserva.\n");
            
            // Remover a reserva encontrada
            for (int i = numeroCheckIN; i < numeroReserva - 1; i++)
            {
                reservas[i] = reservas[i + 1];
            }
            numeroReserva--;
            
            printf("Reserva removida com sucesso!\n");
            getchar();
            limpaTela();
            break;
        }
        else if (simNao == 'S' || simNao == 's')
        {
            printf("\nCheck-in efetuado com sucesso!\n");
            getchar();
            limpaTela();
            break;
        }
        else
        {
            printf("Comando invalido, tente novamente!\n");
            getchar();
            limpaTela();
        }
    }

    return 1;
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
        casoC();
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
        system("pause");
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
        printf("\t# Digite a escolha: ");
        scanf("%c",&opcao);
        getchar();
        limpaTela();
    } while (escolha(opcao));
    
    return 0;
}