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
        void solve();
        void export_components(unsigned count, bool last = false) const;

    private:
        std::map<short, std::vector<short>> components_;
};
static double temp = 6666666;
static double tau = 0.999;
static double stop = 0.000001;
static constexpr int optimum = 200;
