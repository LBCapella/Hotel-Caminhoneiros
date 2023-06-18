//VDC-Hotel-01
//Carlos Gouveia, Kau� Cordeiro, Luan Capella, Pedro Gabriel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//checkout; checkIN sem reserva;

void bannerHotel()//Funcao para apresentar o banner do hotel
{
    printf("========================================================================\n\n\n");
    printf("                      HOTEL CALIFORNIA CAMINHONEIROS                    \n\n\n");
    printf("========================================================================\n\n");
}

void menuApresentacao()//Funcao para banner do menu para o inicio do programa
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

void limpaTela()//Funcao para limpar a tela
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

void menuEscolha()//Funcao para o menu de escolhas 
{
    bannerHotel();

    printf("\t# Para acessar a lista de quartos e o mapa do hotel digite : 'A'\n");
    printf("\t# Para fazer reserva digite : 'B'\n");
    printf("\t# Para fazer checkin digite : 'C'\n");
    printf("\t# Para Cancelar a reserva digite : 'D'\n");
    printf("\t# Para acessar o menu do restaurante digite : 'E'\n");
    printf("\t# Para fazer checkout digite : 'F'\n");
    printf("\t# Para Ver a lista de reservas digite : 'G'\n");
    printf("\t# Para acessar a taxa de ocupacao do hotel digite : 'H'\n");
    printf("\t# Para vizualizar a situacao de um determinado quarto : 'I'\n");
    printf("\t# Para sair do programa digite : 'J'\n");
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
    char status[50];
} reserva;


//Definindo Constante para armazenar reservas:
 #define MAX_RESERVAS 280
 reserva reservas[MAX_RESERVAS];
 int numeroReserva = 0;
 reserva checkIN[MAX_RESERVAS];
 int contagemCheckin = 0;

void tabelaQuartos()//Funcao para mostrar o mapa do hotel 
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

void cadastroHospede()
{
    reserva novaReserva;

    tabelaQuartos();
    
    int andarValido = 0;
    
    if(numeroReserva == 20*14)
    {
    	printf("Nenhum quarto disponivel!");
    	printf("digite ENTER para voltar ao menu!");
    	getchar();
	}

	printf("\nPreencha as informacoes abaixo:\n");

    printf("------------------------------------------------------------------------\n\n");

    while(!andarValido)
    {
        printf("Diga o andar e o quarto(Ex: 1 3) ou digite (0 0) para voltar ao menu: ");
        scanf("%d %d", &novaReserva.andar, &novaReserva.quarto);
        getchar();

        if (novaReserva.andar == 0)
        {
            printf("Voltando ao menu!\n");
            getchar();
            limpaTela();
            break;
        }

        else if (novaReserva.andar < 1 || novaReserva.andar > 20) 
        {
            printf("\nAndar invalido! Tente novamente!\n\n");
        } 
        
        else if (novaReserva.quarto < 1 || novaReserva.quarto > 14) 
        {
            printf("\nQuarto invalido! Tente novamente!\n\n");
        } 
        
        else 
        {
            andarValido = 1; // Valor de andar/quarto valido, sai do loop
        }
    }

    if (andarValido == 1)
    {
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
            

        reservas[numeroReserva] = novaReserva; 
        numeroReserva++;

        limpaTela();
        printf("========================================================================\n\n\n");
        printf("                              FAZER RESERVA                             \n\n\n");
        printf("========================================================================\n\n");
        tabelaQuartos();
        printf("\nReserva cadastrada com sucesso!\n");
        printf("===============================================\n");
        printf("Pressione Enter para voltar ao menu principal...");
        getchar();
        limpaTela();
    }
               
}


void quartos(char nome[], int valor, int primeiroAndar, int segundoAndar)
{
    bannerHotel();

    printf("==============================================\n");
    printf("      DETALHES DO QUARTO - %s\n", nome);
    printf("==============================================\n\n");

    printf("PRECO: %d R$\n\n", valor);

    printf("ANDARES DISPONIVEIS: %d ao %d\n\n", primeiroAndar, segundoAndar);

    printf("DESCRICAO DO QUARTO:\n\n");

    if (strcmp(nome, "Suite Dream Road") == 0)
    {
        printf("A Suite Dream Road e uma suite luxuosa com uma vista deslumbrante da cidade.\n");
        printf("Possui uma cama king-size e um sofa-cama, acomodando ate 3 pessoas.\n");
        printf("Alem disso, a suite inclui um banheiro privativo com banheira de hidromassagem,\n");
        printf("sala de estar espacosa, TV de tela plana, minibar, cafeteira e Wi-Fi gratuito.\n");
        printf("Os hospedes tambem tem acesso a academia, a piscina e ao servico de concierge do hotel.\n");
    }
    else if (strcmp(nome, "Suite Diesel Oasis") == 0)
    {
        printf("A Suite Diesel Oasis e uma suite tematica para os amantes de carros e velocidade.\n");
        printf("Possui uma cama queen-size e um sofa-cama, acomodando ate 4 pessoas.\n");
        printf("A suite apresenta decoracao moderna com detalhes inspirados no mundo automobilistico.\n");
        printf("Inclui area de estar espacosa, banheiro privativo com chuveiro de hidromassagem,\n");
        printf("TV de tela plana, minibar, mesa de trabalho e Wi-Fi gratuito.\n");
        printf("Os hospedes tambem podem desfrutar do servico de quarto 24 horas e do acesso a piscina do hotel.\n");
    }
    else if (strcmp(nome, "Quarto Trucker's Haven") == 0)
    {
        printf("O Quarto Trucker's Haven e uma opcao aconchegante e confortavel para quem viaja a negocios.\n");
        printf("Possui uma cama de casal, acomodando ate 2 pessoas.\n");
        printf("O quarto inclui uma mesa de trabalho, TV a cabo, minibar e Wi-Fi gratuito.\n");
        printf("Os hospedes tambem tem acesso a um business center, servico de lavanderia e cafe da manha incluso.\n");
    }
    else if (strcmp(nome, "Quarto Midnight Drive") == 0)
    {
        printf("O Quarto Midnight Drive e uma opcao economica para quem busca um lugar simples e confortavel.\n");
        printf("Possui uma cama de solteiro, acomodando 1 pessoa.\n");
        printf("O quarto inclui TV, banheiro privativo e Wi-Fi gratuito.\n");
        printf("Os hospedes podem desfrutar do cafe da manha continental gratuito e do estacionamento do hotel.\n");
    }
    else
    {
        printf("Nao ha informacoes disponiveis sobre este quarto.\n");
    }
    printf("\n");
    tabelaQuartos();
    system("pause");
    limpaTela();
}

void casoA ()//Funcao para mostrar os quartos disponiveis
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

int casoC()//Funcao para fazer chekin
{
    char simNao;
    int verificaCpf;
    reserva checkin;
    int numeroCheckIN = -1; //para indicar que nenhuma reserva foi encontrada.

    while (1)
    {
        printf("========================================================================\n\n\n");
        printf("                              FAZER CHECK-IN                            \n\n\n");
        printf("========================================================================\n\n");

        printf("Caso ja tenha reserva, digite 'S'. Caso contrario, digite 'N': ");
        
        scanf(" %c", &simNao);
        getchar();
        
        limpaTela();

        if (simNao == 'N' || simNao == 'n')
        {
            printf("========================================================================\n\n\n");
            printf("                              FAZER CHECK-IN                            \n\n\n");
            printf("========================================================================\n\n");

            printf("Voce gostaria de efetuar o Check-in sem reserva? (S para sim, N para nao): ");
            scanf(" %c", &simNao);
            getchar();
            limpaTela();

            if (simNao == 'N' || simNao == 'n')
            {
                limpaTela();
                return 0;
            }
                
                
            else if (simNao == 'S' || simNao == 's')
            {
                printf("========================================================================\n\n\n");
                printf("                              FAZER CHECK-IN                            \n\n\n");
                printf("========================================================================\n\n");
                cadastroHospede();
                printf("Digite o CPF para confirmar o checkin: ");
                scanf("%d",&verificaCpf);
                getchar();
                
                for (int i = 0; i < numeroReserva; i++)
                {
                    checkin = reservas[i];
                    if (verificaCpf == checkin.cpf)
                    {
                        checkIN[i] = checkin;
                        contagemCheckin++;
                        break;
                    }
                }

                printf("\ncheckin realizado com sucesso!\n");
                printf("===============================================\n");
                printf("Pressione Enter para continuar...");
                getchar();
                limpaTela();
                return 0; 
            }

            else
            {
                printf("Comando invalido, tente novamente!\n");
                getchar();
                limpaTela();
            }

            
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
    
    while (numeroCheckIN == -1)
    {
        printf("========================================================================\n\n\n");
        printf("                              FAZER CHECK-IN                            \n\n\n");
        printf("========================================================================\n\n");

        printf("Digite o numero do CPF feito na reserva: ");
        scanf("%d", &verificaCpf);
        getchar();
        limpaTela();

        for (int i = 0; i < numeroReserva; i++)
        {
            checkin = reservas[i];
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

    printf("========================================================================\n\n\n");
    printf("                              FAZER CHECK-IN                            \n\n\n");
    printf("========================================================================\n\n");

    printf("Muito bem, encontramos seu CPF, senhor(a) %s!\n", checkin.nome);
    
    while (1)
    {
        printf("Voce gostaria de efetuar o Check-in? (S para sim, N para nao): ");
        scanf(" %c", &simNao);
        getchar();

        if (simNao == 'N' || simNao == 'n')
        {
            printf("\nPois bem, estaremos retirando a sua reserva.\n");
            
            // Remover a reserva encontrada
            for (int i = numeroCheckIN; i < numeroReserva; i++)
            {
                reservas[i] = reservas[i + 1];
            }
            numeroReserva--;

            printf("Reserva removida com sucesso!\n");
            tabelaQuartos();
            getchar();
            limpaTela();
            break;
        }
        else if (simNao == 'S' || simNao == 's')
        {

            for (int i = 0; i < numeroReserva; i++)
            {
                checkin = reservas[i];
                if (verificaCpf == checkin.cpf)
                {
                    checkIN[i] = checkin;
                    contagemCheckin++;
                    break;
                }
            }
            printf("\nCheck-in efetuado com sucesso!\n");
            tabelaQuartos();
            printf("===============================================\n");
            printf("Pressione Enter para continuar...");
            getchar();
            limpaTela();
            return 0; 
            
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

int casoD()//menu de cancelamento de uma reserva
{
    do
    {
        printf("========================================================================\n\n\n");
        printf("                             CANCELAR RESERVA                           \n\n\n");
        printf("========================================================================\n\n");

        int verificaCpf;
        char simNao;

        printf("Gostaria de efetuar o cancelamento da reserva ('S' para sim, 'N' para nao)? \n");
        scanf(" %c", &simNao);
        getchar(); // Consumir o caractere de nova linha pendente no buffer

        if (simNao == 'S' || simNao == 's')
        {
            if (numeroReserva == 0)
            {
                printf("Nenhuma reserva encontrada...\n"
                       "Pressione ENTER para voltar ao menu e efetuar a reserva.");
                getchar();
                limpaTela();
                return 0;
            }
            printf("Digite o numero do CPF feito na reserva: ");
            scanf("%d", &verificaCpf);
            getchar();

            // Removendo reserva
            for (int i = 0; i < numeroReserva; i++)
            {
                reserva r = reservas[i];
                if (verificaCpf == r.cpf)
                {
                    for (int j = i; j < numeroReserva; j++)
                    {
                        reservas[j] = reservas[j + 1];
                    }
                    numeroReserva--;
                }
            }
        
        if (simNao == 'N' || simNao == 'n')
        {
            limpaTela();
            return 0;
        }

        } 
    } while (1);

    printf("Reserva removida com sucesso!\n");
    tabelaQuartos();
    getchar();
    limpaTela();
    return 1;
}


int casoF()//menu do check-out 
{
    do
    {
        printf("========================================================================\n\n\n");
        printf("                             FAZER CHECK-OUT                            \n\n\n");
        printf("========================================================================\n\n");

        int verificaCpf;
        char simNao;
        int numeroCheckIN;
        reserva checkin;

        printf("Gostaria de efetuar o Check-out ('S' para sim, 'N' para nao)? ");
        scanf(" %c", &simNao);
        getchar(); // Consumir o caractere de nova linha pendente no buffer

        if (simNao == 'S' || simNao == 's')
        {
            if (contagemCheckin == 0)
            {
                printf("Nenhum check-in encontrado...\n"
                       "Pressione ENTER para voltar ao menu ");
                getchar();
                limpaTela();
                return 0;
            }
            else
            {
                numeroCheckIN = -1;

                while (numeroCheckIN == -1)
                {
                    printf("Digite o numero do CPF feito no check-in: ");
                    scanf("%d", &verificaCpf);
                    getchar();

                    for (int i = 0; i < numeroReserva; i++)
                    {
                        checkin = reservas[i];
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
                    }
                }

                // Removendo reserva
                for (int i = 0; i < numeroReserva; i++)
                {
                    reserva r = reservas[i];
                    if (verificaCpf == r.cpf)
                    {
                        for (int j = i; j < numeroReserva; j++)
                        {
                            reservas[j] = reservas[j + 1];
                        }
                        numeroReserva--;
                    }
                }

                // Removendo check-in
                for (int i = 0; i < contagemCheckin; i++)
                {
                    reserva c = checkIN[i];
                    if (verificaCpf == c.cpf)
                    {
                        for (int j = i; j < contagemCheckin; j++)
                        {
                            checkIN[j] = checkIN[j + 1];
                        }
                        contagemCheckin--;
                    }
                }

                printf("Checkout feito com sucesso!, obrigado senhor(a) %s\n", checkin.nome);
                tabelaQuartos();
                getchar();
                limpaTela();
                break;
            }
        }

        else //sair do loop caso seja selecionado "N"
        {
            limpaTela();
            break;
        }
    } while (1);

    return 1;
}

void casoE()//cardapio do restaurante
{
    printf("========================================================================\n\n\n");
    printf("                             MENU RESTAURANTE                           \n\n\n");
    printf("========================================================================\n\n");

    printf("Bem vindo(a) ao Restaurante Truck Stop!\n\n");
    printf("Conheca nosso menu especial inspirado na cultura dos caminhoneiros.\n");
    printf("Aproveite as deliciosas opcoes de pratos e a selecao de cervejas geladas.\n\n");

    printf("========== MENU DO RESTAURANTE ==========\n\n");
    printf("----- Pratos -----              ----- Cervejas -----\n\n");
    printf("1. Hamburguer do Estradeiro     7. Cerveja do Asfalto\n");
    printf("2. Bife do Caminhoneiro         8. Cerveja da Boleia\n");
    printf("3. Frango Grelhado do Rodo      9. Cerveja do Ponto\n");
    printf("4. Feijoada do Peso Pesado     10. Cerveja da Estrada\n");
    printf("5. Macarrao a Moda do Viagem   11. Cerveja do Descanso\n");
    printf("6. Picanha do Motorista        12. Cerveja da Carreta\n\n");
    printf("=========================================\n");
    printf("('Enter' para voltar para o menu)");   
    getchar();
    limpaTela();
}

void casoH()//Taxa de Ocupacao
{
    printf("========================================================================\n\n\n");
    printf("                             TAXA DE OCUPACAO                           \n\n\n");
    printf("========================================================================\n\n");
    tabelaQuartos();
    printf("\n-----------------------------------------------------\n");
    float taxaOcupacaoCheck =  (contagemCheckin/(float)MAX_RESERVAS)*100;//variável para receber a porcentagem.
    float taxaOcupacaoReserva =  (numeroReserva/(float)MAX_RESERVAS)*100;
    //caso não haja reservas
    if (numeroReserva == 0)
    {
        printf("Nao ha reservas nem checkin cadastrados no momento, digite ENTER para voltar ao menu.");
        getchar();
        limpaTela();   
    }
    //caso tenha
    else
    {
        printf("A taxa de ocupacao atual do hotel eh %d/%d(%.2f%%)\n\n",contagemCheckin,MAX_RESERVAS,taxaOcupacaoCheck);
        printf("A taxa de reservas atual do hotel eh %d/%d(%.2f%%)\n\n",numeroReserva,MAX_RESERVAS,taxaOcupacaoReserva);
        
		printf("digite ENTER para voltar ao menu!");
        getchar();
        limpaTela();
    }
}

void casoI()//Status do quarto
{
    char simNao;
    while (1)
    {
        reserva verifica;
        printf("========================================================================\n\n\n");
        printf("                               STATUS QUARTO                            \n\n\n");
        printf("========================================================================\n\n");

        tabelaQuartos();
        printf("\n-----------------------------------------------------\n");

        //recebe o valor dado pelo usuario
        printf("\ndigite o quarto (e seu respectivo andar) que deseja verificar (EX: 20 3): ");
        scanf("%d %d", &verifica.andar, &verifica.quarto);
        getchar();

        int encontrado = 0; // Indicador se a reserva foi encontrada(flag)

        //caso nao haja reserva no quarto selecionado
        if (numeroReserva == 0)
        {
            strcpy(verifica.status, "Quarto Vazio");
        }

        else
        {
            for (int i = 0; i < numeroReserva; i++)
            {
                reserva r = reservas[i];
                if (verifica.andar == r.andar && verifica.quarto == r.quarto)
                {
                    encontrado = 1; // Marcar como encontrado

                    for (int j = 0; j < contagemCheckin; j++)
                    {
                        reserva c = checkIN[j];
                        if (verifica.andar == c.andar && verifica.quarto == c.quarto)
                        {
                            verifica = checkIN[j];
                            strcpy(verifica.status, "Ocupado");
                            break; // Sair do loop interno
                        }
                    }

                    if (strcmp(verifica.status, "Ocupado") != 0)
                    {
                        verifica = reservas[i];
                        strcpy(verifica.status, "Reservado");
                    }

                    break; // Sair do loop externo
                }
            }
        }
        //flag para atualizar o status do verifica
        if (!encontrado)
        {
            strcpy(verifica.status, "Quarto Vago");
        }

        if (strcmp(verifica.status, "Quarto Vago") == 0)
        {
            printf("Status: %s\n", verifica.status);
            printf("---------------------------------------------------------\n");
        }

        else
        {
            printf("nome: %s\n", verifica.nome);
            printf("vulgo: %s\n", verifica.vulgo);
            printf("idade: %d\n", verifica.idade);
            printf("CPF: %d\n", verifica.cpf);
            printf("%d Andar, quarto %d\n", verifica.andar, verifica.quarto);
            printf("Status: %s\n", verifica.status);
            printf("---------------------------------------------------------\n");
        }
        // condicao de sim e nao para voltar ao menu ou permanecer no looping
        printf("\nDeseja voltar ao menu? S/N: ");
        scanf(" %c", &simNao);
        getchar();

        if (simNao == 'S' || simNao == 's')
        {
            limpaTela();
            break;
        }
        limpaTela();
    }
}

int escolha(char opcao)//Funcao para falar opcoes de escolha
{
    switch (opcao)
    {
    case 'A':
    case 'a':
        casoA();
        break;

    case 'B':
    case 'b':
        printf("========================================================================\n\n\n");
        printf("                              FAZER RESERVA                             \n\n\n");
        printf("========================================================================\n\n");
        cadastroHospede();
        break;

    case 'C':
    case 'c':
        casoC();
        break;

    case 'D':
    case 'd':
        casoD();
        break;

    case 'E':
    case 'e':
        casoE();
        break;

    case 'F':
    case 'f':
        casoF();
        break;

    case 'G':
    case 'g':
        casoG();
        break;    

    case 'H':
    case 'h':
        casoH();
        break;

    case 'I':
    case 'i':
        casoI();
        break;

    case 'J':
    case 'j':
        return 0;    

    default:
        printf("Opcao digitada invalida, por favor tente novamente.\n");
        system("pause");
        limpaTela();
        break;
    }
    return 1;
}

int main()//Programa principal
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