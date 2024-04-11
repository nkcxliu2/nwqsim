
// include headers from nwq-sim
#include "include/backendManager.hpp"
#include "include/state.hpp"
#include "include/circuit.hpp"
#include "include/nwq_util.hpp"

#include <cmath>
using namespace std;

int main(){
    int n_qubits = 2;
    auto circuit = std::make_shared<Circuit>(n_qubits);

    circuit->H(0);
    circuit->CX(0, 1);

    std::string backend = "CPU";
    std::string sim_method = "sv";
    auto state = BackendManager::create_state(backend, n_qubits, sim_method);

    // Add measurement operation to circuit then simulate
    int shots = 1024;
    circuit->MA(shots);
    state->sim(circuit);
    long long int *result = state->get_results();

    // print out the results
    for(i=0; i< pow(2, n_qubits); i++){
        std::cout << result[i] << '\t';
    }
    std::cout<< std::endl;

    return 0
}