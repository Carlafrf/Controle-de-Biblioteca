#include "biblioteca.h"

using namespace std;

int main() {
	//constru��o de usu�rios, livros e periodicos
	Usuario davi("Davi", "0945133113", "UFMG street, 21", "(31)2535-9052");
	Usuario carla("Carla", "12345678", "UFMG street2, 01", "(31)3464-9052");
	Livro biblia(777, "holy bible", "Editora Moishe", "131", "Jesus de Nazar�", 100);
	Livro kalman(3, "Filtro de Kalman para cura do c�ncer", "Editora Dada", "2018", "Davi Frossard de Jesus", 5);
	Livro quebra(8, "Pau quebra no Kalman", "IEEE", "2017", "Carla Perez", 2);
	Periodico artigo(8, "Robo m�vel", "IEEE", "2017", 1, "fevereiro");

	time_t t = time(NULL); // declara��o de um empr�stimo com data de devolu��o para daqui 4 dias
	tm dataDev = *localtime(&t);
	dataDev.tm_mday += 4;
	mktime(&dataDev);
	Emprestimo proDavi(dataDev, davi);
	Emprestimo praCarla(dataDev, carla);

	Biblioteca bib; // declara��o de uma biblioteca
	bib.inserirUser(davi); // inser��o de usu�rios na biblioteca
	bib.inserirUser(carla);
	bib.inserirPub(biblia); // inser��o de publica��es na biblioteca
	bib.inserirPub(kalman);
	bib.inserirPub(quebra);
	bib.inserirPub(artigo);
	bib.inserirEmp(proDavi); // inser��o de empr�stimos na biblioteca
	bib.inserirEmp(praCarla);
	bib.inserirItemEmp(proDavi, biblia); // inser��o de itens aos empr�stimos da biblioteca
	bib.inserirItemEmp(proDavi, kalman);
	bib.inserirItemEmp(proDavi, quebra);
	bib.inserirItemEmp(praCarla, kalman);
	bib.inserirItemEmp(praCarla, quebra);

	vector<Emprestimo> resultado1 = bib.getEmp(); // obt�m os registros da biblioteca (emprestimos, publica��es e usu�rios)
	vector<std::reference_wrapper<Publicacao>> resultado2 = bib.getPub();
	vector<Usuario> resultado3 = bib.getUser();
	
	vector<Publicacao> resultado4 = bib.pesqPub("Kalman"); // pesquisas nas publica��es da biblioteca
	vector<Publicacao> resultado5 = bib.pesqLivro("Jesus");

	system("pause");
}