#include <iostream>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Função para calcular o número mínimo de ligas necessárias para atender a demanda
int minimumLigas(int demanda, const std::vector<int> &ligas_disponiveis)
{
    // Cria um vetor dp para armazenar as soluções intermediárias
    std::vector<int> solucoes(demanda + 1, INT_MAX);

    // Caso base: para uma demanda de 0, o número mínimo de ligas necessárias é 0
    solucoes[0] = 0;

    // Preenche o vetor solucoes utilizando programação dinâmica
    for (int i = 1; i <= demanda; ++i) // para cada demanda
    {
        for (long unsigned int j = 0; j < ligas_disponiveis.size(); ++j) // para cada liga disponível
        {
            if (ligas_disponiveis[j] <= i)
            {                                                                // se a liga disponível for menor ou igual à demanda
                int subproblema = solucoes[i - ligas_disponiveis[j]];        // calcula o número mínimo de ligas para atender à demanda
                if (subproblema != INT_MAX && subproblema + 1 < solucoes[i]) // se o número mínimo de ligas for menor que o número mínimo atual
                    solucoes[i] = subproblema + 1;                           // atualiza o número mínimo de ligas
            }
        }
    }

    // Retorna o número mínimo de ligas necessárias para atender à demanda
    return solucoes[demanda];
}

int main(int argc, char const *argv[])
{
    int casos; // quantidade de casos de teste
    cin >> casos;
    int demanda, qtd_ligas;                        // demanda e quantidade de ligas disponiveis
    std::vector<int> ligas_disponiveis(qtd_ligas); // vetor com as ligas disponiveis

    for (int i = 0; i < casos; i++) // para cada caso de teste
    {
        ligas_disponiveis.clear();          // limpa o vetor de ligas disponiveis
        cin >> qtd_ligas >> demanda;        // le a quantidade de ligas disponiveis e a demanda
        for (int i = 0; i < qtd_ligas; ++i) // para cada liga disponivel
        {
            int liga;
            cin >> liga;                       // le a liga
            ligas_disponiveis.push_back(liga); // adiciona a liga ao vetor de ligas disponiveis
        }
        cout << minimumLigas(demanda, ligas_disponiveis) << endl; // imprime a quantidade minima de ligas
    }
    return 0;
}
