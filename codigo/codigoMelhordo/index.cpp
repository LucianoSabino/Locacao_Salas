#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

	int disponibilidadeSalas[4][5][7];
	int valores[] = {70, 30, 20, 70, 20, 20, 30};
	std::string codigoTurma[4][5][7] = {};
	char* diaSemana[5] = {"Seg", "Ter", "Qua", "Qui", "Sex"};
	char* hora[5] = {"08h-10h", "10h-12h", "14h-16h", "16h-20h"};
	int capacidadeAlunos = 0, capacidade = 0, horario = 0, diaDaSemana = 0;
	std::string turma;
	int contador70 = 0, contador30 = 0, contador20 = 0, index = 0;
	char continuar;
	
void limparTela() {
    #ifdef _WIN32
        std::system("cls"); // Comando para limpar tela no Windows
    #else
        std::system("clear"); // Comando para limpar tela no Linux e macOS
    #endif
}

int  relocamento(int horarioNovo){
	
	if(horarioNovo > 4){
		horarioNovo = 1;
	}
		
	std::cout << "\nDeseja alocar a turma no horario " << horarioNovo + 1 << "(S/N)? ";
	char opcao;
	std::cin >> opcao;
	
	if(opcao == 'S' || opcao == 's' || opcao == 'p'){
		horario = horarioNovo;
		return horario; 
	}	
}

void procuraSalas(){
	if(capacidadeAlunos == 70){
		for(int sala = 0; sala <= 3; sala++){
			if(disponibilidadeSalas[horario][diaDaSemana][sala] == -1){
				contador70++;
			}
		}
	}else if(capacidadeAlunos == 30){
		for(int sala = 0; sala <= 6; sala++){
			if(disponibilidadeSalas[horario][diaDaSemana][sala] == -3){
				contador30++;
			}
		}
	}else {
		for(int sala = 0; sala < 6; sala++){
			if (disponibilidadeSalas[horario][diaDaSemana][sala] == -2){
				contador20++;
			}
		}
	}
	
	if(contador70 >= 2 && capacidadeAlunos == 70){
		contador70 = 0;
		std::cout << "Nao foi possivel encontrar uma sala disponivel para a turma, no horario: " << horario + 1 << " .";
		int horarioNovo = horario + 1;
		
		relocamento(horarioNovo);
	}else if(contador30 >= 2 && capacidadeAlunos == 30){
		contador30 = 0;
		std::cout << "Nao foi possivel encontrar uma sala disponivel para a turma, no horario: " << horario + 1 << " .";
		int horarioNovo = horario + 1;
		
		relocamento(horarioNovo); 
	}else if(contador20 >= 4 && capacidadeAlunos == 20){
		contador20 = 0;
		std::cout << "Nao foi possivel encontrar uma sala disponivel para a turma, no horario: " << horario + 1 << " .";
		int horarioNovo = horario + 1;
		
		relocamento(horarioNovo);
	}
}

void cadastraTurma(){
	bool valorAdicionado = false;
    for(int h =0; h < 4; h++){
    	for(int d = 0; d < 5; d++){
    		for(int s = 0; s < 7; s++){
    			if (h == horario && d == diaDaSemana) {
            		if (disponibilidadeSalas[h][d][s] == capacidadeAlunos) {
                		if (!valorAdicionado) {
                			if(capacidadeAlunos == 70){
            					disponibilidadeSalas[h][d][s] = -1;
            					codigoTurma[h][d][s] = turma;
            					std::cout << "\nSala cadastrada\n";;
            					valorAdicionado = true;	
            				}if(capacidadeAlunos == 20){
            					disponibilidadeSalas[h][d][s] = -2;
            					codigoTurma[h][d][s] = turma;
            					std::cout << "\nSala cadastrada\n";
            					valorAdicionado = true;	
            				}if(capacidadeAlunos == 30){
            					disponibilidadeSalas[h][d][s] = -3;
            					codigoTurma[h][d][s] = turma;
            					std::cout << "\nSala cadastrada\n";
            					valorAdicionado = true;	
            				}
            			}
            		}
				}	
			}
		}
	}
}
	
int main() {
	for(int t = 0; t < 4; t++){
		for(int d = 0; d < 5; d++){
			for(int s = 0; s < 7; s++){
				disponibilidadeSalas[t][d][s] = valores[index];
				index = (index + 1) % 7;
			}
		}
	}
	
	do{
		std::cout << "|----------------------------------------------Menu Informacao-----------------------------------------------|\n";
		std::cout << "|    		                          Horario      |      Dia Semana                                     |\n";
		std::cout << "|		                      '1' (08h-10h)    |       'Seg': 1                                      |\n";
		std::cout << "|		                      '2' (10h-12h)    |        -------                                      |\n";
		std::cout << "|		                      '3' (14h-16h)    |        -------                                      |\n";
		std::cout << "|		                      '4' (16h-18h)    |       'sex': 5                                      |\n";
		std::cout << "|------------------------------------------------------------------------------------------------------------|\n";
		
		std::cout << "\nDigite o codigo da turma: ";
		std::cin >> turma;
		
		std::cout << "\nQuantos alunos tem nessa turma (01 a 70): ";
		std::cin >> capacidade;
		
		while(capacidade > 70 || capacidade < 1){
			std::cout << "Capacidade invalida! Informe 01 a 70: ";
			std::cin >> capacidade;
		}
		
		if(capacidade <= 70 && capacidade > 30){
			capacidadeAlunos = 70;
		}else if(capacidade <= 30 && capacidade > 20){
			capacidadeAlunos = 30;
		}else if (capacidade >= 1 && capacidade <= 20){
			capacidadeAlunos = 20;
		}
		
		std::cout << "\nQual Horario da semana deseja alocar de (1 a 4)? ";
		std::cin >> horario;
		
		while(horario < 1 || horario > 4){
			std::cout << "\nHorario invalido! Informe 1, 2, 3 ou 4. ";
			std::cin >> horario;
		}
		
		std::cout << "\nDia da semana (Segunda: 1 ... Sexta: 5): ";
		std::cin >> diaDaSemana;
		
		while(diaDaSemana < 1 || diaDaSemana > 5){
			std::cout << "\nDia invalido! Informe um valor entre 1 e 5. ";
			std::cin >> diaDaSemana;	
		}
		
		diaDaSemana--;
		horario--;
		
		procuraSalas();
		cadastraTurma();
		
		std::cout << "\nQuer contimuar: S/N ? ";
        std::cin >> continuar;
        
        limparTela();
	}while(continuar == 'S' || continuar == 's' || continuar == 'p' );
	
	std::cout << "-------------------- A tabela esta organizada com conforme o horario e todos os dias da semana corespondente --------------------";
	for (int h = 0; h < 4; h++) {
		std::cout << "\nHorario: " << hora[h] << "\n";
		std::cout << "Tur: C1 | C2 | C3 | C4 | C5 | C6 | C7 | \n";
        for (int d = 0; d < 5; d++) {
        	std::cout << diaSemana[d] <<": ";
            for (int s = 0; s < 7; s++) {
            	if(codigoTurma[h][d][s] == ""){
            		codigoTurma[h][d][s] = "  ";
            		std::cout << codigoTurma[h][d][s] << " | ";
				}else{
					std::cout << codigoTurma[h][d][s] << " | ";
				}
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}