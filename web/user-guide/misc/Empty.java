// ----- Extra java (option='head') -----


// ----- Imports -----

// ----- Extra java (option='import') -----


/**
 * Class auto-generated by 'cli2java.xsl' - Do not edit!
 * @author cli2java.xsl - CLI library 2.8 (Alexis Royer, http://alexis.royer.free.fr/CLI/)
 */

// ----- Cli class definition -----
 class Empty extends cli.Cli {
    // ----- Sub-menus -----

    // ----- Owner CLI -----
    private Empty m_cliOwnerCli;
    // ----- Menus -----
    private Empty m_clicli_a;
    // ----- Node members -----
    // ----- Extra java (option='members') -----


    // ----- Constructor -----
    public Empty() {
        super("myCLI", new cli.Help());
        this.populate();
        // ----- Extra java (option='constructor') -----

    }

    // ----- Populate -----
    public void populate() {
        // CLI reference
        m_cliOwnerCli = (Empty) getCli();
        // Create menus and populate
        m_cliOwnerCli.m_clicli_a = this;
        // Local nodes
    }

    // ----- Menu execution -----
    public boolean execute(cli.CommandLine CLI_CmdLine) {
        try {
            cli.TraceClass CLI_EXECUTION = new cli.TraceClass("CLI_EXECUTION", new cli.Help().addHelp(cli.Help.LANG_EN, "CLI Execution traces").addHelp(cli.Help.LANG_FR, "Traces d'ex�cution du CLI"));
            java.util.Iterator<cli.Element> cli_Elements = CLI_CmdLine.iterator();
            cli.Element cli_Element = null;
            // myCLI>
            m_clicli_a_lbl:
            {
                cli_Element = cli_Elements.next();
                if (cli_Element == null) return false;
                cli.Traces.trace(CLI_EXECUTION, "context = \"myCLI>\", "+ "word = " + (cli_Element instanceof cli.Endl ? "<CR>" : cli_Element.getKeyword()));
                return false;
            }
        } catch (java.util.NoSuchElementException e1) {
        } catch (java.lang.Exception e) {
            getErrorStream().printStackTrace(e);
        }
        return false;
    }

    public void onExit() {
    }

    public java.lang.String onPrompt() {
        return super.onPrompt();
    }

}

// ----- Extra java (option='tail') -----


