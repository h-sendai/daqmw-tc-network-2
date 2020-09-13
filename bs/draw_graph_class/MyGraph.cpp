#include "MyGraph.h"

using namespace std;

MyGraph::MyGraph(): m_debug(false), m_graph(0), m_text(0)
{
}

MyGraph::MyGraph(const MyGraph &rhs): m_debug(rhs.m_debug), m_x(rhs.m_x), m_y(rhs.m_y)
{
    // XXX //
    if (rhs.m_graph != 0) {
        m_graph = (TGraph*) (rhs.m_graph)->Clone();
    }
    if (rhs.m_text != 0) {
        m_text = (TText *) rhs.m_text->Clone();
    }
}

MyGraph::~MyGraph()
{
    delete m_graph;
    delete m_text;
}

int MyGraph::set_debug()
{
    m_debug = true;
    return 0;
}

int MyGraph::unset_debug()
{
    m_debug = false;
    return 0;
}

int MyGraph::init(unsigned int x_size = 1024, unsigned int y_size = 1024)
{
    m_graph = new TGraph();
    m_text  = new TText();

    m_text->SetTextSize(0.05);
    m_text->SetTextColor(kBlack);
    m_text->SetNDC(1);

    m_x.reserve(x_size);
    m_y.reserve(y_size);

    return 0;
}

int MyGraph::fill(unsigned int x, unsigned short y)
{
    m_x.push_back(x);
    m_y.push_back(y);

    return 0;
}

int MyGraph::set_title(string title)
{
    m_graph->SetTitle(title.c_str());
    return 0;
}

int MyGraph::set_min_max(int lower_y, int upper_y)
{
    m_graph->SetMinimum(lower_y);
    m_graph->SetMaximum(upper_y);

    return 0;
}

int MyGraph::draw()
{
    int n_points = m_x.size();
    for (int i = 0; i < n_points; ++i) {
        m_graph->SetPoint(i, m_x.at(i), m_y.at(i));
    }

    m_graph->Draw("al*");

    return 0;
}

int MyGraph::reset()
{
    m_x.clear();
    m_y.clear();

    return 0;
}

int MyGraph::dump()
{
    for (unsigned int i = 0; i < m_x.size(); ++i) {
        cerr << m_x.at(i) << " " << m_y.at(i) << endl;
    }

    return 0;
}
