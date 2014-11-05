#include <iostream>
#include <vector>
#include <string>

#include "Registo.h"
#include "Utilizador.h"

using namespace std;

void Utilizador::setNome(string nome)
{
	this->nome = nome;
}

void Utilizador::setIdade(int idade)
{
	this->idade = idade;
}

string Utilizador::getNome() const {return nome;}

int Utilizador::getIdade() const {return idade;}

vector<Registo *> Utilizador::getRegs() const {return registos;}

void Utilizador::setRegs(vector<Registo *> regs)
{
	registos = regs;
}

Registo Utilizador::ultimoReg() const
{
	int pos = registos.size() - 1;

	return *registos[pos];
}

bool Utilizador::operator==(string name)
{
	if (nome == name)
		return true;
	return false;
}

bool Utilizador::operator==(Utilizador user)
{
	if (nome == user.nome)
		return true;
	return false;
}

void Utilizador::operator=(Utilizador user)
{
	nome = user.nome;
	idade = user.idade;
	password = user.password;

	vector<Registo*> regs2 = user.getRegs();

	for (unsigned int i = 0; i < regs2.size(); i++)
	{
		Registo *ptr;
		ptr = new(Registo);
		*ptr = *regs2[i];
		registos.push_back(ptr);
	}
}