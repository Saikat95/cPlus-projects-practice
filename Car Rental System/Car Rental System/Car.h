class Car{
    private:
        char plate_num[10];
        char brand[10];
        char model[10];
        float capacity;
        char color[10];
        float rate_per_hour;
        float rate_per_day;
        char transmission[6];

    public:
        int countCar();
        void addNewCar();
        void carData(int);
        void showCarData();
};
