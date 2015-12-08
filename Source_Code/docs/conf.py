import sys
import os
import shlex
import subprocess

read_the_docs_build = os.environ.get('READTHEDOCS', None) == 'True'

if read_the_docs_build:
    subprocess.call('doxygen', shell=True)

extensions = ['breathe']
breathe_projects = { 'Source_Code': 'xml' }
breathe_default_project = "Source_Code"
templates_path = ['_templates']
source_suffix = '.rst'
master_doc = 'index'
project = u'Source_Code'
copyright = u'2015, Source_Code'
author = u'Source_Code'
version = '1.0'
release = '1.0'
language = None
exclude_patterns = ['_build']
pygments_style = 'sphinx'
todo_include_todos = False
html_static_path = ['_static']
htmlhelp_basename = 'Source_Codedoc'
latex_elements = {
}
latex_documents = [
  (master_doc, 'Source_Code.tex', u'Source\_Code Documentation',
   u'Source\_Code', 'manual'),
]
