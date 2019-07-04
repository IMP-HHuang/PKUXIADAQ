# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# http://www.sphinx-doc.org/en/master/config

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))


# -- Project information -----------------------------------------------------

project = 'PKUXIADAQ'
copyright = '2019, Hongyi Wu(吴鸿毅)'
author = 'Hongyi Wu(吴鸿毅)'

# The full version, including alpha/beta/rc tags
release = 'beta'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'recommonmark',
    'sphinx.ext.mathjax',
    'sphinx.ext.todo',
    'sphinx.ext.autodoc',
    'sphinx.ext.viewcode',
    'sphinx.ext.graphviz',
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# The language for content autogenerated by Sphinx. Refer to documentation
# for a list of supported languages.
#
# This is also used if you do content translation via gettext catalogs.
# Usually you set "language" from the command line for these cases.
language = 'zh_CN'

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = []


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'sphinx_rtd_theme'  #'alabaster'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']




source_suffix = {
    '.rst': 'restructuredtext',
    '.md': 'markdown',
}

latex_logo = ''
latex_engine = 'xelatex'

latex_elements = {
    # The paper size ('letterpaper' or 'a4paper').
'papersize': 'a4paper',

# The font size ('10pt', '11pt' or '12pt').
    #'pointsize': '10pt',

# Additional stuff for the LaTeX preamble.
    #'preamble': '',

# Latex figure (float) alignment
    #'figure_align': 'htbp',

'preamble' : r'''
  \usepackage[slantfont,boldfont]{xeCJK} 
\newCJKfontfamily{\song}{SimSun}
\newCJKfontfamily{\hei}{SimHei}
\newCJKfontfamily{\kai}{KaiTi}
\newCJKfontfamily{\fangsong}{FangSong}

\setmainfont{Times New Roman}%文档正文默认英语字体,设置衬线字体
\setCJKmainfont[BoldFont={SimSun},ItalicFont={KaiTi}]{SimSun}%设置默认中文字体
\setCJKsansfont{SimHei}
\setCJKmonofont{FangSong}% 设置等宽字体
        ''',
}
