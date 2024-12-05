/*
 * CS106L Assignment 4: Weather Forecast
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 */

#include <algorithm>
#include <random>
#include <vector>
#include <iostream>


/* #### Please feel free to use these values, but don't change them! #### */
double kMaxTempRequirement = 5;
double uAvgTempRequirement = 60;

struct Forecast {
  double min_temp;
  double max_temp;
  double avg_temp;
};

Forecast compute_forecast(const std::vector<double>& dailyWeather) {
  // STUDENT TODO 1: return a forecast for the daily weather that is passed in.
  double min_temp = *(std::min_element(dailyWeather.cbegin(), dailyWeather.cend()));
  double max_temp = *(std::max_element(dailyWeather.cbegin(), dailyWeather.cend()));
  double total_temp = std::accumulate(dailyWeather.cbegin(), dailyWeather.cend(), 0.0);
  return {min_temp, max_temp, total_temp / dailyWeather.size()};
}

std::vector<Forecast> get_forecasts(const std::vector<std::vector<double>>& weatherData) {
  /*
   * STUDENT TODO 2: returns a vector of Forecast structs for the weatherData which contains
   * std::vector<double> which contain values for the weather on that day.
   */
  std::vector<Forecast> vf(weatherData.size());
  auto pred = [](std::vector<double> v) {
    return compute_forecast(v);
  };
  std::transform(weatherData.begin(), weatherData.end(), vf.begin(), pred);
  return vf;
}

std::vector<Forecast> get_filtered_data(const std::vector<Forecast>& forecastData) {
  // STUDENT TODO 3: return a vector with Forecasts filtered for days with specific weather.
  std::vector<Forecast> vf{forecastData};
  auto pred = [] (Forecast f) {
    return !((f.max_temp - f.min_temp) > kMaxTempRequirement && f.avg_temp >= uAvgTempRequirement);
  };
  auto iter = std::remove_if(vf.begin(), vf.end(), pred);
  vf.erase(iter, vf.end());
  return vf;
}


std::vector<Forecast> get_shuffled_data(const std::vector<Forecast>& forecastData) {
  // STUDENT TODO 4: Make use of a standard library algorithm to shuffle the data!
  std::vector<Forecast> vf{forecastData};
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(vf.begin(), vf.end(), g);
  return vf;
}

std::vector<Forecast> run_weather_pipeline(const std::vector<std::vector<double>>& weatherData) {
  // STUDENT TODO 5: Put your functions together to run the weather pipeline!
  auto  vf = get_forecasts(weatherData);
  vf = get_filtered_data(vf);
  return get_shuffled_data(vf);
}

/* #### Please don't change this line! #### */
#include "utils.cpp"