//
// Created by joyjo on 2023-03-21.
//

#ifndef PJC_GENOME_H
#define PJC_GENOME_H

#include <list>
#include <string>

namespace ga {
    template <typename gene, typename phenotype>
    class Genome {
        Genome();
        ~Genome();
        std::list<gene> genome;
        virtual phenotype decode();
    };

} // ga

#endif //PJC_GENOME_H
