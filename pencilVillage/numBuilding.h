struct numBuildings
{
    int total;
    int townCentreLevel;
    int barracks;
    int farm;
    int house;
    int mill;
    int outpost;
    int stables;
    int depot;
    int quarry;
    int armourer;
    int guildhall;
    int church;
    int overseer;
    int tower;
    int forum;
    int tinker;
    int prospector;
    const int maxHouse;
    const int maxMill;
    const int maxQuarry;
    const int maxArmourer;
    const int maxChurch;
    const int maxOverseer;
    const int maxTower;
    const int maxForum;
    const int maxTinker;
    const int maxProspector;
    const int maxTownCentre;

    numBuildings() : total(0), townCentreLevel(1), maxHouse(4), maxMill(4), maxQuarry(4), maxArmourer(3), maxChurch(3), maxOverseer(3), maxTower(2), maxForum(2), maxTinker(2), maxProspector(2), maxTownCentre(4) {}
};