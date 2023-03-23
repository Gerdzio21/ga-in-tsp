//
// Created by joyjo on 2023-03-21.
//

#ifndef PJC_GENETICALGORITHM_H
#define PJC_GENETICALGORITHM_H

#include "Generation.h"
#include "Genome.h"
#include <list>


namespace ga {
    template <typename gene, typename phenotype>
    class GeneticAlgorithm {
        GeneticAlgorithm();
        ~GeneticAlgorithm();
        int numberOfAncestorsGenerations;
        Generation<gene,phenotype>  generations[];

        virtual void startReproductionProcess() = 0;
        virtual Generation<gene,phenotype> getFinalGeneration() = 0;
        virtual Genome<gene,phenotype> getFinalRepresentant() = 0; //maybe move to generation class
    };
} // ga

#endif //PJC_GENETICALGORITHM_H
