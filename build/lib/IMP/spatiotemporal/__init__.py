from .create_DAG import create_DAG  # noqa: F401


__version__ = "develop-31a501ea3f"

def get_module_version():
    '''Return the version of this module, as a string'''
    return "develop-31a501ea3f"

def get_module_name():
    '''Return the fully-qualified name of this module'''
    return "IMP::spatiotemporal"

def get_data_path(fname):
    '''Return the full path to one of this module's data files'''
    import IMP
    return IMP._get_module_data_path("spatiotemporal", fname)

def get_example_path(fname):
    '''Return the full path to one of this module's example files'''
    import IMP
    return IMP._get_module_example_path("spatiotemporal", fname)
