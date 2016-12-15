#include "StatisticsWiki.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


class WikiGraph {
    string *titles;
    unsigned int pages, n_links;
    unsigned int *sizes;
    unsigned int *links;
    unsigned int *redirect;
    unsigned int *offset;
    unsigned int *num_of_links_from;
    unsigned int *num_of_links_to;
    unsigned int *num_of_redirects_to;

public:

    WikiGraph(string filename) {

        ifstream file(filename);
        file >> pages >> n_links;

        titles = new string[pages];
        sizes = new unsigned int[pages];
        links = new unsigned int[n_links];
        redirect = new unsigned int[pages];
        offset = new unsigned int[pages + 1];
        num_of_links_from = new unsigned int[pages];
        num_of_links_to = new unsigned int[pages];
        num_of_redirects_to = new unsigned int[pages];

        offset[0] = 0;
        unsigned int curr_link = 0;

        for (int i = 0; i < pages; i++) {
            string title;
            file >> title;
            titles[i] = title;
            unsigned int size, redir, num_of_links;
            file >> size >> redir >> num_of_links;
            sizes[i] = size;
            redirect[i] = redir;
            num_of_links_from[i] = num_of_links;
            offset[i + 1] = offset[i] + num_of_links;

            for (int j = curr_link; j < curr_link + num_of_links; j++) {
                unsigned int link;
                file >> link;
                links[j] = link;
                num_of_links_to[links[j]] += 1;
                if (redirect[i]) {
                    num_of_redirects_to[links[j]] += 1;
                }
            }

            curr_link += num_of_links;
        }

        cout << "Graph has been uploaded." << endl;
    }

    unsigned int get_number_of_links_from(unsigned int id) {
        return num_of_links_from[id];
    }

    unsigned int get_number_of_liks_to(unsigned int id) {
        return num_of_links_to[id];
    }

    unsigned int get_number_of_redirects(unsigned int id) {
        return num_of_redirects_to[id];
    }

    bool is_redirect(unsigned int id) {
        return redirect[id] == 1;
    }

    string get_title(unsigned int id) {
        return titles[id];
    }

    int get_id(string title) {
        for (int i = 0; i < pages; i++)
            if (title == get_title(i))
                return i;
        cerr << "Page not found!" << endl;
        return -1;
    }

    unsigned int get_page_size(unsigned int id) {
        return sizes[id];
    }


};


int main() {
    WikiGraph graph("wiki_smaller_most_ahahah");
    //cout << graph.get_id("Windows_98");
    return 0;
}