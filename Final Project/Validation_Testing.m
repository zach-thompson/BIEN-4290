%% Validation Testing - Visual Comparison

% load image
image = imread('AOsub_OS_confocal_0005_ref_132_lps_12_lbss_10_250um T.tif');

% load our data
data = sortrows(readmatrix('AOsub_OS_confocal_0005_ref_132_lps_12_lbss_10_250um T_coords.csv'),1);

% load sample data
s_data = sortrows(readmatrix('AOsub_OS_confocal_0007_ref_58_lps_12_lbss_10_250um S_coords.csv'),1);

% display image and overlay data plot
imshow(image)
hold on
scatter(s_data(:,1), s_data(:,2),16,'filled')

%% Validation Testing - Quantitative Comparison

% compare number of data points in each file and calculate the % error
size_compare = (size(data, 1) == size(s_data, 1));
size_error = (abs((size(data, 1) - size(s_data, 1))) / size(s_data, 1)) * 100;

% determine distance to the nearest sample point for all points
% store distance if within (min_dist) pixels
distance = NaN([size(data, 1), 1]);
min_dist = 3;
for i = 1:size(data, 1)
    for j = 1:size(s_data, 1)
        a = abs( data(i, 1) - s_data(j, 1) );
        b = abs( data(i, 2) - s_data(j, 2) );
        c = sqrt(a^2 + b^2);
        if (c <= min_dist)
            distance(i) = c;
        end
    end
end

% calculate the mean distance and stddev between point pairs
% (ignore NaN values)
mean_distance = nanmean(distance);
stddev_distance = nanstd(distance);


