#include <vector>
#include <MvcGameView.h>
#include <GoFishConfig.h>

#include "GoFishGame.h"
#include "Log.h"

#include "CLI/CLI.hpp"

int cli11Example(int argc, char **argv);
int playGame();

int main(int argc, char *argv[]) {
    int simple = 0;
    if (simple) {
        CLI::App app;

        bool flag_bool;
        app.add_flag("--bool,-b", flag_bool, "This is a bool flag");

        int flag_int;
        app.add_flag("-i,--int", flag_int, "This is an int flag");

        CLI::Option *flag_plain = app.add_flag("--plain,-p", "This is a plain flag");

        CLI11_PARSE(app, argc, argv);
    } else {
        cli11Example(argc, argv);
    }

    initLogger( "mylogfile.log", ldebug1);

    GoFishConfig config;
    GoFishGame game = config.getGame();
    game.deal();

    for (int i = 0; i < 20; ++i) {
        game.playRound(i + 1);
        if (game.checkWinner(i + 1)) {
            break;
        }
    }

    endLogger();
    return 0;
}

int cli11Example(int argc, char **argv) {
    CLI::App app{"Geet, a command line git lookalike that does nothing"};
    app.require_subcommand(1);
    auto add = app.add_subcommand("add", "Add file(s)");

    bool add_update;
    add->add_flag("-u,--update", add_update, "Add updated files only");

    std::vector<std::string> add_files;
    add->add_option("files", add_files, "Files to add");

    add->callback([&]() {
        std::cout << "Adding:";
        if(add_files.empty()) {
            if(add_update)
                std::cout << " all updated files";
            else
                std::cout << " all files";
        } else {
            for(auto file : add_files)
                std::cout << " " << file;
        }
    });

    auto commit = app.add_subcommand("commit", "Commit files");

    std::string commit_message;
    commit->add_option("-m,--message", commit_message, "A message")->required();

    commit->callback([&]() { std::cout << "Commit message: " << commit_message; });

    CLI11_PARSE(app, argc, argv);

    std::cout << "\nThanks for using geet!\n" << std::endl;
    return 0;
}
