# Collect all source files using wildcard.py
logic_cards = run_command(
    ['python3', '..' / 'tools' / 'wildcard.py'],
    check: true
)

# Split stdout into a list of filenames
all_sources = logic_cards.stdout().strip().split('\n')

# Filter only .c, .cpp, .m, .mm files
logic_source = []
foreach f : all_sources
    ext = f.split('.')[-1]
    if ext == 'c' or ext == 'cpp' or ext == 'm' or ext == 'mm'
        logic_source += [f]
    endif
endforeach

# Map extensions to suffixes for executable names
suffix_map = {
    'c': '_c',
    'cpp': '_cpp',
    'm': '_objc',
    'mm': '_objcpp'
}

# Create an executable for each source file
foreach src : logic_source
    fname = files(src).name()
    ext = files(src).extension()
    exe_name = fname.replace(ext, '') + suffix_map[ext]
    executable(
        exe_name,
        src,
        dependencies: [dependency('fossil-io')]
    )
endforeach