#include "hashmap.h"
#include <iostream>
#include <string.h>
#include <new>

HashMap::HashMap(int s){
	size = s;
	map = new std::vector < std::list<Pair>* >;
	(*map).resize(s);
	for (int i = 0; i < s; i++){
		(*map)[i] = new std::list<Pair>;
		(*(*map)[i]).resize(0);
	}
	p = 10017;
}

HashMap::~HashMap(){
	delete map;
}

long long HashMap::Hash(char* s){
	long long hs = 0;
	for (int i = 0; i < strlen(s); i++){
		long long power = 1;
		for (int j = 0; j < i; j++) power *= p;
		hs += ((int)s[i] * power) % size;
	}
	return hs;
}

std::list<Pair>::iterator find_place(char* key, long long hs, std::vector < std::list<Pair>* >* map){
	std::list<Pair>::iterator it1 = (*(*map)[hs]).end();
	for (std::list<Pair>::iterator it = (*(*map)[hs]).begin(); it != (*(*map)[hs]).end(); it++){
		if ((*it).key == key){
			it1 = it;
		}
	}
	return it1;
}

void HashMap::Add(char* key, char* val){
	long long hs = HashMap::Hash(key);
	std::list<Pair>::iterator it1 = find_place(key, hs, map);
	if (it1 != (*(*map)[hs]).end()){
		std::cout << "ERROR! This key already exists" << '\n';
	}else{
		Pair tmp;
		tmp.key = key;
		tmp.val = val;
		(*(*map)[hs]).push_back(tmp);
	}
}

void HashMap::Remove(char* key){
	long long hs = HashMap::Hash(key);
	std::list<Pair>::iterator it1 = find_place(key, hs, map);
	if (it1 == (*(*map)[hs]).end()){
		std::cout << "ERROR! There is no such element" << '\n';
	}else{
		(*(*map)[hs]).erase(it1);
	}
}

char* HashMap::Get(char* key){
	long long hs = HashMap::Hash(key);
	for (std::list<Pair>::iterator it = (*(*map)[hs]).begin(); it != (*(*map)[hs]).end(); it++){
		if ((*it).key == key){
			return (*it).val;
		}
	}
	std::cout << "ERROR! There is no such element" << '\n';
}

bool HashMap::Contains(char* key){
	long long hs = HashMap::Hash(key);
	for (std::list<Pair>::iterator it = (*(*map)[hs]).begin(); it != (*(*map)[hs]).end(); it++){
		if ((*it).key == key){
			return true;
		}
	}
	return false;
}