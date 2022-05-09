#include <iostream>
#include <vector>

struct Rooms {
    std::string type ="living";
    double area = 0;
};

struct Floors {
    int nRooms = 2;
    double height = 0;
    std::vector<Rooms> rooms;
};

struct Buildings {
    std::string type ="house";
    std::string pipe = "";
    double area = 0;
    int nFloors = 1;
    std::vector<Floors> floors;
};

struct LandPlot {
    int serialNumber = 0;
    double area = 0;
    int nBuildings = 1;
    std::vector<Buildings> builds;
};

struct Village {
    int nLandPlots = 0;
    std::vector<LandPlot> landPlot;
};

int main() {
    system("chcp 65001");
    std::cout << " Модель данных для посёлка." << std::endl;
    Village village;
    std::cout << " Введите количество земельных участков: ";
    std::cin >> village.nLandPlots;
    for (int i = 0; i < village.nLandPlots; ++i) {
        LandPlot land;
        std::cout << " Введите уникальный номер " << i + 1 << " участка: ";
        std::cin >> land.serialNumber;
        std::cout << " Введите площадь " << i + 1 << " земельного участка: ";
        std::cin >> land.area;
        std::cout << " Введите количество построек " << i + 1 << " земельного участка: ";
        do std::cin >> land.nBuildings;
        while (land.nBuildings < 1);
        for (int j = 0; j < land.nBuildings; ++j) {
            Buildings build;
            std::cout << " Введите тип " << j + 1 << " сооружения (house/garage/barn/shed/bathhouse): ";
            do std::cin >> build.type;
            while (build.type != "house" && build.type != "garage" &&
                   build.type != "barn" && build.type != "shed" &&
                   build.type != "bathhouse");
            if (build.type == "house" || build.type == "bathhouse") {
                std::cout << " Есть ли печь с трубой (yes/no)? ";
                std::string answer;
                std::cin >> answer;
                answer == "yes" ? build.pipe = "pipe" : build.pipe = "";
            }
            std::cout << " Введите площадь " << j + 1 << " сооружения: ";
            do std::cin >> build.area;
            while (build.area > land.area);
            if (build.type == "house") {
                std::cout << " Введите количество этажей " << j + 1 << " сооружения (1-3): ";
                do std::cin >> build.nFloors;
                while (build.nFloors < 1 || build.nFloors > 3);
                for (int k = 0; k < build.nFloors; ++k) {
                    Floors floor;
                    std::cout << " Введите высоту комнат на " << k + 1 << " этаже: ";
                    std::cin >> floor.height;
                    std::cout << " Введите количество комнат на " << k + 1 << " этаже (2-4): ";
                    do std::cin >> floor.nRooms;
                    while (floor.nRooms < 2 || floor.nRooms > 4);
                    for (int h = 0; h < floor.nRooms; ++h) {
                        Rooms room;
                        std::cout << " Введите тип " << h + 1 << " комнаты (bedroom/kitchen/bathroom/children's/living): ";
                        do std::cin >> room.type;
                        while (room.type != "bedroom" && room.type != "kitchen" &&
                               room.type != "bathroom" && room.type != "children's" &&
                               room.type != "living");
                        std::cout << " Введите площадь " << h + 1 << " комнаты: ";
                        do std::cin >> room.area;
                        while (room.area > build.area);
                        floor.rooms.push_back(room);
                    }
                    build.floors.push_back(floor);
                }
            }
            land.builds.push_back(build);
        }
        village.landPlot.push_back(land);
    }
    double sumLandArea = 0, sumBuildsArea = 0;
    for (int i = 0; i < village.nLandPlots; ++i) {
        sumLandArea += village.landPlot[i].area;
        for (int j = 0; j < village.landPlot[i].nBuildings; ++j)
            sumBuildsArea += village.landPlot[i].builds[j].area;
    }
    std::cout << " Занимаемая площадь сооружений составляет: " << sumBuildsArea / sumLandArea * 100 << " %." << std::endl;
    return 0;
}