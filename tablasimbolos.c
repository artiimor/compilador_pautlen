#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablasimbolos.h"

TablaSimbolos *ts = NULL;

void crearAmbitoGlobal()
{
    TablaSimbolos *p_tabla = NULL;
    p_tabla = (TablaSimbolos *)calloc(1, sizeof(TablaSimbolos));
    if (!p_tabla)
        return NULL;
    p_tabla->contexto_global = crear_tabla(TH_SIZE);
    if (!p_tabla->contexto_global)
    {
        free(p_tabla);
        return NULL;
    }
    p_tabla->contexto_local = NULL;
    ts = p_tabla;
}

void cerrarAmbitos()
{
    if (!ts)
        return;
    liberar_tabla(ts->contexto_global);
    if (!ts->contexto_local)
        liberar_tabla(ts->contexto_local);
    free(ts);
}

STATUS insertarSimbolo(const char *lexema, INFO_SIMBOLO *info)
{
    TABLA_HASH *tabla_hash = NULL;
    if (ts == NULL || info == NULL)
    {
        
        return ERR;
    }
    if (ts->contexto_local != NULL)
        tabla_hash = ts->contexto_local;
    else
        tabla_hash = ts->contexto_global;
    
    return insertar_simbolo(tabla_hash, info->lexema, info->categoria, info->tipo, info->clase, info->adicional1, info->adicional2);
}

INFO_SIMBOLO *buscarSimbolo(const char *lexema)
{
    INFO_SIMBOLO *ret = NULL;
    if (!ts || !lexema)
        return ERR;
    if (ts->contexto_local)
    {
        ret = buscar_simbolo(ts->contexto_local, lexema);
        if (ret)
        {
            return ret;
        }
    }
    return buscar_simbolo(ts->contexto_global, lexema);
}

STATUS crearAmbitoLocal(const char *lexema, INFO_SIMBOLO *info)
{
    if (!ts || !info)
    {
        return ERR;
    }

    if (ts->contexto_local)
    {
        return ERR;
    }

    ts->contexto_local = crear_tabla(TH_SIZE);
    if (!ts->contexto_local)
    {
        return ERR;
    }
    if (insertar_simbolo(ts->contexto_global, info->lexema, info->categoria, info->tipo, info->clase, info->adicional1, info->adicional2) == ERR)
    {
        liberar_tabla(ts->contexto_local);
        ts->contexto_local = NULL;
        return ERR;
    }
    if (insertar_simbolo(ts->contexto_local, info->lexema, info->categoria, info->tipo, info->clase, info->adicional1, info->adicional2) == ERR)
    {
        liberar_tabla(ts->contexto_local);
        ts->contexto_local = NULL;
        return ERR;
    }

    return OK;
}

STATUS cerrarAmbitoLocal()
{
    if (!ts)
    {
        return ERR;
    }
    if (!ts->contexto_local)
    {
        return ERR;
    }
    liberar_tabla(ts->contexto_local);
    ts->contexto_local = NULL;
    return OK;
}

int es_local (const char *lexema)
{
    INFO_SIMBOLO *ret = NULL;
    if (!ts || !lexema)
        return ERR;
    if (ts->contexto_local)
    {
        ret = buscar_simbolo(ts->contexto_local, lexema);
        if (ret)
        {
            return 1;
        }
    }
    ret = buscar_simbolo(ts->contexto_global, lexema);
        if (ret)
        {
            return 0;
        }
    return -1;
}