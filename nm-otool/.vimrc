version 6.0
if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <F5> mqggVG=`qzza
nmap gx <Plug>NetrwBrowseX
nmap <F1> :Stdheader
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
noremap <F6> :!norminette %
noremap <F5> mqggVG=`qzz
imap jk 
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set background=dark
set backspace=indent,eol,start
set cindent
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set hidden
set hlsearch
set ignorecase
set incsearch
set laststatus=2
set modelines=1
set runtimepath=~/.vim,~/.vim/bundle/hexmode,~/.vim/bundle/vim-colors-solarized,/usr/share/vim/vimfiles,/usr/share/vim/vim73,/usr/share/vim/vimfiles/after,~/.vim/after
set shiftwidth=4
set showmatch
set smartcase
set smartindent
set tabstop=4
set window=0
" vim: set ft=vim :
