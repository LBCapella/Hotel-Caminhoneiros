#include <stdio.h>
#include <stdlib.h>

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

    printf("\t\t# Para acessar a lista de quartos vagos digite : 'A'\n");
    printf("\t\t# Para fazer reserva digite : 'B'\n");
    printf("\t\t# Para fazer checkin digite : 'C'\n");
    printf("\t\t# Para efetuar uma troca de quarto digite : 'D'\n");
    printf("\t\t# Para acessar o menu do restaurante digite : 'E'\n");
    printf("\t\t# Para sair do programa digite : 'F'\n");
}

int escolha(char opcao)
{
    switch (opcao)
    {
    case 'A':
    case 'a':
        /* code */
        break;

    case 'B':
    case 'b':
        /* code */
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
        return 0;

    default:
        printf("Opcao digitada invalida, por favor tente novamente.");
        break;
    }
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
        limpaTela();
    } while (escolha(opcao));
    
    return 0;
}
