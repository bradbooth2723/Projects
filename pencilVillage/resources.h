struct resources
{
    int maxResources;  //both maxResources and maxPopulation are a function of # of buildings 
    int maxPopulation;
    int wood;
    int stone;
    int gold;
    int population;

    resources() : maxResources(4), maxPopulation(7), wood(3), population(5) {}
};
