#!/bin/bash

# ---------------------------------------------------------
# Script de Testes - Metodos Elementares de Ordenacao
# ---------------------------------------------------------

# Troque para 1 se quiser rodar com Valgrind, ou 0 para normal
USAR_VALGRIND=0

# Comando base do seu executavel
EXECUTAVEL="./main"

if [ "$USAR_VALGRIND" -eq 1 ]; then
    CMD_PREFIX="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q "
    echo "=== MODO VALGRIND ATIVADO ==="
else
    CMD_PREFIX=""
    echo "=== MODO VALGRIND DESATIVADO ==="
fi

TAMANHOS=(1000 10000 100000)
PREFIXOS=("1K" "10K" "100K")
CASOS=("sorted" "nearly_sorted" "reverse_sorted" "unif_rand")

echo "Iniciando bateria de testes..."
echo "==================================================="

for caso in "${CASOS[@]}"; do
    echo ">> Testando caso: $caso"
    for i in "${!TAMANHOS[@]}"; do
        tam="${TAMANHOS[$i]}"
        pref="${PREFIXOS[$i]}"

        ARQUIVO_IN="../in/${caso}/${pref}${caso}.txt"

        if [ -f "$ARQUIVO_IN" ]; then
            echo "   -> Tamanho $tam [$pref]:"
            $CMD_PREFIX $EXECUTAVEL $tam < "$ARQUIVO_IN"
        else
            ARQUIVO_IN_ALT="../in/${caso}/${pref}.txt"
            if [ -f "$ARQUIVO_IN_ALT" ]; then
                echo "   -> Tamanho $tam [$pref]:"
                $CMD_PREFIX $EXECUTAVEL $tam < "$ARQUIVO_IN_ALT"
            else
                echo "   [ERRO] Arquivo de entrada nao encontrado: $ARQUIVO_IN"
            fi
        fi
    done
    echo "---------------------------------------------------"
done

echo "Testes concluidos!"