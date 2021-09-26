#pragma once
class OffTheField
{
    int cur_pos_x;
    int cur_pos_y;
    int new_pos_x;
    int new_pos_y;
    std::string m_message;
public:
    OffTheField(int c_x, int c_y, int n_x, int n_y) :
            cur_pos_x(c_x), cur_pos_y(c_y), new_pos_x(n_x), new_pos_y(n_y), m_message("")
    {
        if (new_pos_x > 10 || new_pos_x < 1)
        {
            m_message += "Ошибка координаты X! Робот выходит за границу поля!\n";
            m_message += '[' + std::to_string(cur_pos_x) + ';' + std::to_string(cur_pos_y) + "] => [" +
                         std::to_string(new_pos_x) + ';' + std::to_string(new_pos_y) + "]\n";
        }
        if (new_pos_y > 10 || new_pos_y < 1)
        {
            m_message += "Ошибка координаты Y! Робот выходит за границу поля!\n";
            m_message += '[' + std::to_string(cur_pos_x) + ';' + std::to_string(cur_pos_y) + "] => [" +
                         std::to_string(new_pos_x) + ';' + std::to_string(new_pos_y) + "]\n";
        }
    }

    const std::string& getInfo() const
    {
        return m_message;
    }
};

class IllegalCommand
{
private:
    int cur_pos_x;
    int cur_pos_y;
    int new_pos_x;
    int new_pos_y;
    std::string m_message;
public:
    IllegalCommand(int c_x, int c_y, int n_x, int n_y) :
            cur_pos_x(c_x), cur_pos_y(c_y), new_pos_x(n_x), new_pos_y(n_y), m_message("")
    {
        if (abs(cur_pos_x - new_pos_x) > 1)
        {
            m_message += "Ошибка координаты X! Шаг слишком велик!\n";
            m_message += '[' + std::to_string(cur_pos_x) + ';' + std::to_string(cur_pos_y) + "] => [" +
                         std::to_string(new_pos_x) + ';' + std::to_string(new_pos_y) + "]\n";
        }

        if (abs(cur_pos_y - new_pos_y) > 1)
        {
            m_message += "Ошибка координаты Y! Шаг слишком велик!\n";
            m_message += '[' + std::to_string(cur_pos_x) + ';' + std::to_string(cur_pos_y) + "] => [" +
                         std::to_string(new_pos_x) + ';' + std::to_string(new_pos_y) + "]\n";
        }

        if (cur_pos_x == new_pos_x && cur_pos_y == new_pos_y)
        {
            m_message += "Ошибка координаты X и Y! Нельзя шагнуть на текущее место!\n";
            m_message += '[' + std::to_string(cur_pos_x) + ';' + std::to_string(cur_pos_y) + "] => [" +
                         std::to_string(new_pos_x) + ';' + std::to_string(new_pos_y) + "]\n";
        }
    }

    const std::string& getInfo() const
    {
        return m_message;
    }
};

class Robot
{
private:
    int pos_x;
    int pos_y;
public:
    Robot(int x = 5, int y = 5) : pos_x(x), pos_y(y)
    {
        std::cout << "Начальная позиция робота: [" << pos_x << ';' << pos_y << ']' << std::endl;
    }

    void move(int x, int y)
    {
        if (abs(pos_x - x) > 1 || abs(pos_y - y) > 1 || (pos_x == x && pos_y == y))
            throw IllegalCommand(pos_x, pos_y, x, y);
        if (x > 10 || x < 1 || y > 10 || y < 1)
            throw OffTheField(pos_x, pos_y, x, y);

        std::cout << "Робот шагнул [" << pos_x << ';' << pos_y << "] => [" << x << ';' << y << ']' << std::endl;

        pos_x = x;
        pos_y = y;
    }
};



