#!/usr/bin/env sh


LD_LIBRARY_PATH="/home/catherine/imp/build/lib:/home/catherine/imp/build/lib:$LD_LIBRARY_PATH"
export LD_LIBRARY_PATH

PYTHONPATH="/home/catherine/imp/build/lib:/home/catherine/imp/build/lib:$PYTHONPATH"
export PYTHONPATH

# Where to find data for the various modules
IMP_DATA="/home/catherine/imp/build/data"
export IMP_DATA

# Extra places to look for imp modules
IMP_EXAMPLE_DATA="/home/catherine/imp/build/doc/examples"
export IMP_EXAMPLE_DATA

# Location of binaries (for wine builds, which don't get PATH)
IMP_BIN_DIR="/home/catherine/imp/build/bin"
export IMP_BIN_DIR

PATH="/home/catherine/imp/build/bin:/home/catherine/imp/build/module_bin/EMageFit:/home/catherine/imp/build/module_bin/algebra:/home/catherine/imp/build/module_bin/atom:/home/catherine/imp/build/module_bin/benchmark:/home/catherine/imp/build/module_bin/cgal:/home/catherine/imp/build/module_bin/container:/home/catherine/imp/build/module_bin/core:/home/catherine/imp/build/module_bin/display:/home/catherine/imp/build/module_bin/domino:/home/catherine/imp/build/module_bin/em:/home/catherine/imp/build/module_bin/em2d:/home/catherine/imp/build/module_bin/example:/home/catherine/imp/build/module_bin/foxs:/home/catherine/imp/build/module_bin/gsl:/home/catherine/imp/build/module_bin/integrative_docking:/home/catherine/imp/build/module_bin/isd:/home/catherine/imp/build/module_bin/kernel:/home/catherine/imp/build/module_bin/kinematics:/home/catherine/imp/build/module_bin/kmeans:/home/catherine/imp/build/module_bin/misc:/home/catherine/imp/build/module_bin/mmcif:/home/catherine/imp/build/module_bin/modeller:/home/catherine/imp/build/module_bin/mpi:/home/catherine/imp/build/module_bin/multi_state:/home/catherine/imp/build/module_bin/multifit:/home/catherine/imp/build/module_bin/npc:/home/catherine/imp/build/module_bin/parallel:/home/catherine/imp/build/module_bin/pepdock:/home/catherine/imp/build/module_bin/pmi:/home/catherine/imp/build/module_bin/rmf:/home/catherine/imp/build/module_bin/rotamer:/home/catherine/imp/build/module_bin/saxs:/home/catherine/imp/build/module_bin/saxs_merge:/home/catherine/imp/build/module_bin/score_functor:/home/catherine/imp/build/module_bin/scratch:/home/catherine/imp/build/module_bin/spatiotemporal:/home/catherine/imp/build/module_bin/spb:/home/catherine/imp/build/module_bin/statistics:/home/catherine/imp/build/module_bin/symmetry:/home/catherine/imp/build/module_bin/test:$PATH"
export PATH


IMP_TMP_DIR="/home/catherine/imp/build/tmp"
export IMP_TMP_DIR


mkdir -p "${IMP_TMP_DIR}"

exec ${precommand} "$@"