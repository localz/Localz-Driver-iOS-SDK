Pod::Spec.new do |s|

	s.name	= 'LocalzDriverSDK'
	s.summary = 'LocalzDriverSDK'

	s.version = '2.1.0'
	s.platform = :ios,'10.0'
	s.ios.deployment_target = '10.0'

	s.homepage = 'http://www.localz.com'
	s.license = {
		:type => 'Commercial',
		:text => <<-LICENSE
			Copyright 2020 Localz Pty Ltd.
			LICENSE
	}
	s.author = { 'Localz Pty Ltd' => 'info@localz.com' }
	s.source = { :git => 'https://github.com/localz/Localz-Driver-iOS-SDK.git',
				 :tag => s.version }
	s.requires_arc = true
	s.xcconfig = { 'FRAMEWORK_SEARCH_PATHS' => '$(inherited)' }
        s.frameworks = 'CoreLocation','SystemConfiguration','Foundation'
	s.vendored_frameworks = 'LocalzDriverSDK/LocalzDriverSDK.framework'
	s.dependency 'SpotzRTSDK', '~> 3.4.5-alpha'
	s.dependency 'LocalzPushSDK'
end
