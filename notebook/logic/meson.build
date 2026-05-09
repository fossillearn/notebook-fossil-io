# Collect all source files using wildcard.py
logic_cards = run_command(['python3', '..' / 'tools' / 'wildcard.py'], check: true)
logic_names = run_command(['python3', '..' / 'tools' / 'basename.py'], check: true)

# Split stdout into a list of filenames
all_sources = logic_cards.stdout().strip().split('\n')

# Use logic_names from basename.py for executable names
all_names   = logic_names.stdout().strip().split('\n')

# Create an executable for each source file using names from logic_names
foreach i : range(0, all_sources.length())
    src = all_sources[i]
    exe_name = all_names[i]
    executable(
        exe_name,
        src,
        dependencies: [dependency('fossil-io')]
    )
endforeach