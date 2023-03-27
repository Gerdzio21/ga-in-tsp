//
// Created by joyjo on 2023-03-21.
//

#ifndef PJC_GENERATION_H
#define PJC_GENERATION_H
#include <list>
#include "Genome.h"

namespace ga {
    template <typename gene, typename phenotype>
    class Generation {
        std::list<Genome<gene,phenotype>> generation;
        Generation();
        ~Generation();

        virtual void createNewGeneration() =0;
        virtual Generation<gene,phenotype> getCurrentGeneration();
        virtual void cross();
        virtual void mutate();
        virtual void evaluate();

    };

} // ga

#endif //PJC_GENERATION_H
