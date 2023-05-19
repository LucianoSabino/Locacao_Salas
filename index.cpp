#include <iostream>
#include <vector>
#include <string>

int main() {
	
//	Iniciando as matrizes
	int disponibilidadeSalas[4][5][7]; 
//	auxiliarTurmas[4][5][7] = {{{0}}};
//	char codigoSalas[4][5][7];
//	int valores[7] ;
//	int contadores[7] = {0};
	
	char* diaSemana[5] = {"Seg", "Ter", "Qua", "Qui", "Sex"};
	std::string codigoTurma[4][5][7] = {};
	int contadorSala = 4;
	
//	Preenchendo a matriz com os valores especificos
    
    for (int h = 0; h < 4; h++) {
        for (int d = 0; d < 5; d++) {
            for (int s = 0; s < 7; s++) {
                if (s < 2) {
                    disponibilidadeSalas[h][d][s] = 70;
                } else if (s < 4) {
                    disponibilidadeSalas[h][d][s] = 30;
                } else {
                    disponibilidadeSalas[h][d][s] = 20;
                }
            }
        }
    }
    
    
	char continuar;
	std::string turma;
	int capacidadeAlunos, capacidade, horario, diaDaSemana;
	int contador70 = 0, contador30 = 0, contador20 = 0;
	
	do{
		std::cout << "Qual o codigo da turma: ";
		std::cin >> turma;
		
		std::cout << "\nQuantos alunos tem nessa turma (20, 30 e 70): ";
		std::cin >> capacidade;
		if( capacidade > 70){
        	std::cout << "Capacidade invalida! Informe 20 a 70: ";
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
		
		if(horario < 1 && horario > 4){
			std::cout << "\nHor?rio invalido! Informe 1, 2, 3 ou 4. ";
			std::cin >> horario;
			horario--;
		}else{
			horario--;
		}
		std::cout << "\nDia da semana (Segunda: 1 ... Sexta: 5): ";
		std::cin >> diaDaSemana;
		
		if(diaDaSemana >= 1 && diaDaSemana <= 5){
			diaDaSemana--;
		}else{
			std::cout << "\nDia invalido! Informe um valor entre 1 e 5. ";
			std::cin >> diaDaSemana;
			diaDaSemana--;
		}
		std::cout << "\nQuer contimuar: S/N ? ";
        std::cin >> continuar;
        
    	if(capacidadeAlunos == 70 || capacidadeAlunos == 30){
	        for(int sala = 0 ; sala <= 2; sala++){
	        	if (capacidadeAlunos == 70){
	        		if (disponibilidadeSalas[horario][diaDaSemana][sala] == -1){
						contador70++;
					}	
				}if (capacidadeAlunos == 30){
	        		if (disponibilidadeSalas[horario][diaDaSemana][sala] == -3){
						contador30++;
					}	
				}
			}
		}
		if(capacidadeAlunos == 20){
			for(int sala =0; sala < 7; sala++){
				if (disponibilidadeSalas[horario][diaDaSemana][sala] == -2){
					contador20++;
				}
			}
		}
		
		
		
		if(contador70 >= 2 && capacidadeAlunos == 70){
			contador70 = 0;
			std::cout << "Nao foi possivel encontrar uma sala disponivel para a turma, no horario: " << horario + 1 << " .";
			int novoHorario = horario + 1;
			
			if(novoHorario > 4){
				novoHorario = 1;
			}
			std::cout << "\nDEseja alocar a turma no horario" << novoHorario << "(S/N)? ";
			char opcao;
			std::cin >> opcao;
			
			if (opcao == 's' || opcao == 'S' || opcao == 'p'){
				
				horario = novoHorario;
				
				bool valorAdicionado = false;
				
				capacidadeAlunos = 70;
				
		        for(int h =0; h < 4; h++){
		        	for(int d = 0; d < 5; d++){
		        		for(int s = 0; s < 7; s++){
		        			if (h == horario && d == diaDaSemana) {
		                		if (disponibilidadeSalas[h][d][s] == capacidadeAlunos) {
		                			std::cout << "Cheguei aqui";
		                    		if (!valorAdicionado) {
		                    			if(capacidadeAlunos == 70){
			            					disponibilidadeSalas[h][d][s] = -1;
			            					std::cout << "\nSala cadastrada de 70 alunos no horario \n";
			            					valorAdicionado = true;	
			            				}
		                			}
		                		}
							}	
						}
					}
				}
				
				std::cout << "\nQuer contimuar: S/N ? ";
        		std::cin >> continuar;
			}
			
		}else if (contador30 >= 2 && capacidadeAlunos == 30){
			contador30 = 0;
			std::cout << "Erro 30\n";
			
		} else if (capacidadeAlunos == 20 && contador20 >=4){
			contador20 = 0;
			std::cout << "Erro 20\n";
			
		}else{
			
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
		            					contadorSala ++;
		            					std::cout << "\nSala cadastrada de 70 alunos\n";;
		            					valorAdicionado = true;	
		            				}if(capacidadeAlunos == 20){
		            					disponibilidadeSalas[h][d][s] = -2;
		            					contadorSala++;
		            					codigoTurma[h][d][s] = turma;
		            					std::cout << "\nSala cadastrada de 20 alunos\n";
		            					valorAdicionado = true;	
		            				}if(capacidadeAlunos == 30){
		            					disponibilidadeSalas[h][d][s] = -3;
		            					codigoTurma[h][d][s] = turma;
		            					contadorSala++;
		            					std::cout << "\nSala cadastrada de 30 alunos\n";
		            					valorAdicionado = true;	
		            				}
	                			}
	                		}
						}	
					}
				}
			}
			
		}
        
	
	
		
	}while(continuar == 'S' || continuar == 's' || continuar == 'p');
	
	char* hora[5] = {"08h-10h", "10h-12h", "14h-16h", "16h-20h"};
	
	int test;
	
	for (int h = 0; h < 4; h++) {
		std::cout << "\nHorario: " << hora[h] << "\n";
		std::cout << "Tur: C1 70 30 30 20 20 20 \n";
        for (int d = 0; d < 5; d++) {
        	std::cout << diaSemana[d] <<": ";
            for (int s = 0; s < 7; s++) {
            	test = test+1;
                std::cout << codigoTurma[h][d][s] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
	
	
}