function matrix2latexmatrix(matrix, filename)

% function: matrix2latexmatrix(...)
% Author:   N. Marcacci Rossi
% Contact:  nicolamr@gmail.com
% Version:  1.0
% Date:     September, 29, 2010

% This software is published under the GNU GPL, by the free software
% foundation. For further reading see: http://www.gnu.org/licenses/licenses.html#GPL

% Usage:
% matrix2latexmatrix(matrix, filename, varargs)
% where
%   - matrix is a 2 dimensional numerical or cell array
%   - filename is a valid filename, in which the resulting latex code will
%   be stored
%
% Example input:
%   matrix = [1.5 1.764; 3.523 0.2];
%   rowLabels = {'row 1', 'row 2'};
%   columnLabels = {'col 1', 'col 2'};
%   matrix2latex(matrix, 'out.tex', 'rowLabels', rowLabels, 'columnLabels', columnLabels, 'alignment', 'c', 'format', '%-6.2f', 'size', 'tiny');
%
% The resulting latex file can be included into any latex document by:
% /input{out.tex}
%
% Enjoy life!!!

    fid = fopen(filename, 'w');
    
    width = size(matrix, 2);
    height = size(matrix, 1);

    if isnumeric(matrix)
        matrix = num2cell(matrix);
        for h=1:height
            for w=1:width
                matrix{h, w} = num2str(matrix{h, w});
            end
        end
    end
    
    fprintf(fid, '\\begin{pmatrix}\r\n');
    
    for h=1:height
        for w=1:width-1
            fprintf(fid, '%s&', matrix{h, w});
        end
        fprintf(fid, '%s\\\\\r\n', matrix{h, width});
    end

    fprintf(fid, '\\end{pmatrix}\r\n');

    fclose(fid);