/*
 * memtable.h
 *
 *  Created on: 15 jun. 2019
 *      Author: utnso
 */

#ifndef MEMTABLE_H_
	#define MEMTABLE_H_

	#include "config/config_LFS.h"
	#include <inttypes.h>

		typedef struct{
			char* tabla;
			t_list* registros;
		} fila_memtable;

		typedef struct {
			uint64_t timestamp;
			u_int16_t key;
			char* value;
		} fila_registros;

	fila_memtable* create_memtable(char* tabla);
	fila_memtable* obtener_tabla(char *nombre_tabla);
	void insert_memtable(char* tabla,fila_registros* registro);
	t_list* obtener_tabla_registros(fila_memtable* ftabla, u_int16_t key);
	t_list* select_memtable(char* tabla,u_int16_t key);
	void liberar_registros(fila_registros* registro);
	void liberador_registros(fila_memtable* ftabla);
	void drop_memtable(char* tabla);
	void liberar_tablas(fila_memtable* ftabla);
	void liberar_tablas_memtable(t_list* memtable);
	void liberar_memtable();

	pthread_mutex_t mem_mutex;


#endif /* MEMTABLE_H_ */
