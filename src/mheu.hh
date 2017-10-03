#include <map>

class Recruit
{
    public:
        Recruit();
        ~Recruit();
        void init_initial_state();
        short compute_total_length() const;
        void swap(short key1, short key2);
        void randomize();

    private:
        std::map<short, std::vector<short>> components_;
};
static constexpr float temp = 1995;
static constexpr float step = 0.99;
static constexpr float stop = 0.01;
