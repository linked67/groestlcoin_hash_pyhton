from distutils.core import setup, Extension

groestlcoin_hash_module = Extension('groestlcoin_hash',
                               sources = ['groestlcoinmodule.c',
                                          'groestlcoin.c',
										  'sph/groestl.c',
										  'sph/sha2.c'],
                               include_dirs=['.', './sph'])


setup (name = 'groestlcoin_hashs',
       version = '0.1',
       description = 'Bindings for Groestl Used by MyriadCoin',
       ext_modules = [groestlcoin_hash_module])
